#include <__oo2c.h>
#include <__config.h>
#include <Thread/Semaphore.d>

#include <errno.h>
#include <stdio.h>
#include <semaphore.h>

void Thread_Semaphore__SemaphoreDesc_INIT(Thread_Semaphore__Semaphore s,
					OOC_INT32 value) {
  s->sem = RT0__NewBlock(sizeof(sem_t));
  Thread_PThread__CheckError(sem_init((sem_t*)s->sem, 0, value), OOC_TRUE);
}

void Thread_Semaphore__SemaphoreDesc_Post(Thread_Semaphore__Semaphore s) {
  Thread_PThread__CheckError(sem_post((sem_t*)s->sem), OOC_TRUE);
}

void Thread_Semaphore__SemaphoreDesc_Wait(Thread_Semaphore__Semaphore s) {
  int rc;
  
  do {
    rc = sem_wait((sem_t*)s->sem);
  } while (rc == EINTR);
}

OOC_BOOLEAN Thread_Semaphore__SemaphoreDesc_TryWait(Thread_Semaphore__Semaphore s) {
  int rc;
  
  do {
    rc = sem_trywait((sem_t*)s->sem);
  } while (rc == EINTR);
  return (rc == 0);
}

OOC_INT32 Thread_Semaphore__SemaphoreDesc_GetValue(Thread_Semaphore__Semaphore s) {
  int sval;
  sem_getvalue((sem_t*)s->sem, &sval);  /* always returns 0 */
  return sval;
}

void Thread_Semaphore__SemaphoreDesc_Destroy(Thread_Semaphore__Semaphore s) {
  Thread_PThread__CheckError(sem_destroy((sem_t*)s->sem), OOC_TRUE);
  s->sem = NULL;
}

void OOC_Thread_Semaphore_init() {
}

void OOC_Thread_Semaphore_destroy() {
}
