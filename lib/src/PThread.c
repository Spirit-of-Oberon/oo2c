#include <__oo2c.h>
#include <__config.h>
#include <PThread.d>

#include <errno.h>
#include <stdio.h>
#include <pthread.h>
#include <signal.h>


void PThread__ErrorDesc_INIT(PThread__Error e, Object__String msg,
			     OOC_INT32 errorCode) {
  Exception__ExceptionDesc_INIT((Exception__Exception)e, msg);
  e->errorCode = errorCode;
}

static void check_error(int errorCode, int fatal) {
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
    default:
      sprintf(buffer, "Unknown error code (%i)", errorCode);
      str = buffer;
    }
    
    e = RT0__NewObject(OOC_TYPE_DESCR(PThread,ErrorDesc));
    PThread__ErrorDesc_INIT((PThread__Error)e,
			    (Object__String)Object__NewLatin1(str, 64),
			    errorCode);
    if (fatal) {
      Exception__Abort(e);
    } else {
      Exception__Raise(e);
    }
  }
}



void PThread__ThreadDesc_INIT(PThread__Thread t) {
  t->thread = NULL;
}

void PThread__ThreadDesc_Run(PThread__Thread t) {
  /* abstract method */
}

void PThread__ThreadDesc_Start(PThread__Thread t) {
  sigset_t oldmask, newmask;
  int rc;
  void* (*start)(void*) =
    (void*(*)(void*))OOC_METHOD(t, PThread__ThreadDesc_Run);
  
  /* Mask all signals in the current thread before creating the new
   * thread.  This causes the new thread to start with all signals
   * blocked.
   */
  sigfillset(&newmask);
  pthread_sigmask(SIG_BLOCK, &newmask, &oldmask);
  rc = pthread_create((pthread_t*)&t->thread, NULL, start, t);
  pthread_sigmask(SIG_SETMASK, &oldmask, NULL);
  check_error(rc, OOC_FALSE);
}

void PThread__ThreadDesc_Join(PThread__Thread t) {
  void *exit_code;
  
  check_error(pthread_join((pthread_t)t->thread, &exit_code), OOC_FALSE);
}



void PThread__MutexDesc_INIT(PThread__Mutex m) {
  m->mutex = RT0__NewBlock(sizeof(pthread_mutex_t));
  pthread_mutex_init((pthread_mutex_t*)m->mutex, NULL);  /* always returns 0 */
}

void PThread__MutexDesc_Lock(PThread__Mutex m) {
  check_error(pthread_mutex_lock((pthread_mutex_t*)m->mutex), OOC_TRUE);
}

void PThread__MutexDesc_Unlock(PThread__Mutex m) {
  check_error(pthread_mutex_unlock((pthread_mutex_t*)m->mutex), OOC_TRUE);
}

void PThread__MutexDesc_Destroy(PThread__Mutex m) {
  check_error(pthread_mutex_destroy((pthread_mutex_t*)m->mutex), OOC_TRUE);
  m->mutex = NULL;
}


void OOC_PThread_init() {
}

