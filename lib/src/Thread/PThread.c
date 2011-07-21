#include <__oo2c.h>
#include <__config.h>
#include <Thread/PThread.d>

#include <errno.h>
#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <math.h>

#if defined(HAVE_LIBGC) && defined(HAVE_GC_GC_H)
#  include <gc/gc.h>
#endif

static Thread_PThread__Thread main_thread;
static pthread_key_t threadobj_key;

void Thread_PThread__ErrorDesc_INIT(Thread_PThread__Error e, Object__String msg,
			     OOC_INT32 errorCode) {
  Exception__ExceptionDesc_INIT((Exception__Exception)e, msg);
  e->errorCode = errorCode;
}

void Thread_PThread__CheckError(OOC_INT32 errorCode, OOC_BOOLEAN fatal) {
  if (errorCode) {
    Exception__Exception e;
    char buffer[64];
    char *str;
    
    switch (errorCode) {
    case EAGAIN:
      str = "Insufficient resources (EAGAIN)"; break;
    case EINVAL:
      str = "Invalid arguments (EINVAL)"; break;
    case ESRCH:
      str = "No such thread (ESRCH)";
    case EDEADLK:
      str = "Deadlock (EDEADLK)";
    case EBUSY:
      str = "Resource in use (EBUSY)";
    case ENOSYS:
      str = "Not supported (ENOSYS)";
    default:
      sprintf(buffer, "Unknown error code (%i)", errorCode);
      str = buffer;
    }
    
    e = RT0__NewObject(OOC_TYPE_DESCR(Thread_PThread,ErrorDesc));
    Thread_PThread__ErrorDesc_INIT((Thread_PThread__Error)e,
			    (Object__String)Object__NewLatin1(str, 64),
			    errorCode);
    if (fatal) {
      Exception__Abort(e);
    } else {
      Exception__Raise(e);
    }
  }
}



void Thread_PThread__ThreadDesc_INIT(Thread_PThread__Thread t) {
  Exception__InitThreadState(&t->exceptionState);
  t->thread = NULL;
}

void Thread_PThread__ThreadDesc_Run(Thread_PThread__Thread t) {
  /* abstract method */
}

void Thread_PThread__ThreadDesc_RunWrapper(Thread_PThread__Thread t) {
  /* make the thread's object available as thread specific data */
  pthread_setspecific(threadobj_key, t);
  
  /* because the thread's stack of exception handlers is cleared, any
     exception raised by the Run() method will end up in the default
     handler of Exception.ActivateContext() */
  OOC_METHOD(t, Thread_PThread__ThreadDesc_Run)(t);
}

void Thread_PThread__ThreadDesc_Start(Thread_PThread__Thread t) {
  sigset_t oldmask, newmask;
  int rc;
  void* (*start)(void*) =
    (void*(*)(void*))OOC_METHOD(t, Thread_PThread__ThreadDesc_RunWrapper);
  
  /* Mask all signals in the current thread before creating the new
   * thread.  This causes the new thread to start with all signals
   * blocked.
   */
  sigfillset(&newmask);
  pthread_sigmask(SIG_BLOCK, &newmask, &oldmask);
  rc = pthread_create((pthread_t*)&t->thread, NULL, start, t);
  pthread_sigmask(SIG_SETMASK, &oldmask, NULL);
  Thread_PThread__CheckError(rc, OOC_FALSE);
}

void Thread_PThread__ThreadDesc_Join(Thread_PThread__Thread t) {
  void *exit_code;
  
  Thread_PThread__CheckError(pthread_join((pthread_t)t->thread, &exit_code), OOC_FALSE);
}

#define THIS_THREAD ((Thread_PThread__Thread)pthread_getspecific(threadobj_key))
Thread_PThread__Thread Thread_PThread__CurrentThread() {
  return THIS_THREAD;
}



void Thread_PThread__MutexDesc_INIT(Thread_PThread__Mutex m) {
  m->mutex = RT0__NewBlock(sizeof(pthread_mutex_t));
  pthread_mutex_init((pthread_mutex_t*)m->mutex, NULL);  /* always returns 0 */
}

void Thread_PThread__MutexDesc_Lock(Thread_PThread__Mutex m) {
  Thread_PThread__CheckError(pthread_mutex_lock((pthread_mutex_t*)m->mutex), OOC_TRUE);
}

OOC_BOOLEAN Thread_PThread__MutexDesc_TryLock(Thread_PThread__Mutex m) {
  int res;

  res = pthread_mutex_trylock((pthread_mutex_t*)m->mutex);
  if (res && (res != EBUSY)) {
    Thread_PThread__CheckError(res, OOC_TRUE);
  }
  return (res == 0);
}

void Thread_PThread__MutexDesc_Unlock(Thread_PThread__Mutex m) {
  Thread_PThread__CheckError(pthread_mutex_unlock((pthread_mutex_t*)m->mutex), OOC_TRUE);
}

void Thread_PThread__MutexDesc_Destroy(Thread_PThread__Mutex m) {
  Thread_PThread__CheckError(pthread_mutex_destroy((pthread_mutex_t*)m->mutex), OOC_TRUE);
  m->mutex = NULL;
}



void Thread_PThread__ConditionDesc_INIT(Thread_PThread__Condition c) {
  c->cond = RT0__NewBlock(sizeof(pthread_cond_t));
  pthread_cond_init((pthread_cond_t*)c->cond, NULL);  /* always returns 0 */
}

void Thread_PThread__ConditionDesc_Signal(Thread_PThread__Condition c) {
  pthread_cond_signal((pthread_cond_t*)c->cond);  /* always returns 0 */
}

void Thread_PThread__ConditionDesc_Broadcast(Thread_PThread__Condition c) {
  pthread_cond_broadcast((pthread_cond_t*)c->cond);  /* always returns 0 */
}

void Thread_PThread__ConditionDesc_Wait(Thread_PThread__Condition c, Thread_PThread__Mutex m) {
  pthread_cond_wait((pthread_cond_t*)c->cond, (pthread_mutex_t*)m->mutex);
  /* always returns 0 */
}

OOC_BOOLEAN Thread_PThread__ConditionDesc_TimedWait(Thread_PThread__Condition c, Thread_PThread__Mutex m, OOC_REAL64 absTime) {
  double sec;
  double frac = modf(absTime, &sec);
  struct timespec t;
  int rc;
  
  t.tv_sec = (long int)sec;
  t.tv_nsec = (long int)frac*1e9;
  
  /*{
    struct tm tt;
    char str[1024];
    time_t time = t.tv_sec;
    
    strftime(str, 1024, "%a, %d %b %Y %H:%M:%S %z", localtime_r(&time, &tt));
    printf("time: %s, nsec=%li\n", str, t.tv_nsec);
  }*/
  
  do {
    rc = pthread_cond_timedwait((pthread_cond_t*)c->cond,
				(pthread_mutex_t*)m->mutex,
				&t);
  } while (rc == EINTR);
  return (rc != ETIMEDOUT);
}

void Thread_PThread__ConditionDesc_Destroy(Thread_PThread__Condition c) {
  Thread_PThread__CheckError(pthread_cond_destroy((pthread_cond_t*)c->cond), OOC_TRUE);
  c->cond = NULL;
}



static Exception__ThreadStatePtr tls_GetThreadState() {
  return &THIS_THREAD->exceptionState;
}

void OOC_Thread_PThread_init() {
  pthread_key_create(&threadobj_key, NULL);
  Exception__GetThreadState = tls_GetThreadState;
  
  main_thread = RT0__NewObject(OOC_TYPE_DESCR(Thread_PThread,ThreadDesc));
  Thread_PThread__ThreadDesc_INIT(main_thread);
  pthread_setspecific(threadobj_key, main_thread);
}

void OOC_Thread_PThread_destroy() {
  /* FIXME... if we ever to module unloading  */
}
