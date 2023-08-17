#include "ulock.h"
#include "x86.h"
#include "defs.h"

void init_lock(struct lock_t *s) {
    s->locked = 0;
}

void 
acquire_lock(struct lock_t *s) 
{
    /* Your Code */
    // The xchg is atomic.
    while(xchg(&s->locked, 1) != 0)
      ;

  // Tell the C compiler and the processor to not move loads or stores
  // past this point, to ensure that the critical section's memory
  // references happen after the lock is acquired.
   __sync_synchronize();
}

void 
release_lock(struct lock_t *s) 
{
    /* Your Code */
    // Tell the C compiler and the processor to not move loads or stores
  // past this point, to ensure that all the stores in the critical
  // section are visible to other cores before the lock is released.
  // Both the C compiler and the hardware may re-order loads and
  // stores; __sync_synchronize() tells them both not to.
   __sync_synchronize();

  // Release the lock, equivalent to lk->locked = 0.
  // This code can't use a C assignment, since it might
  // not be atomic. A real OS would use C atomics here.
   asm volatile("movl $0, %0" : "+m" (s->locked) : );

}


void 
init_sem(struct sem_t *s, int initval)
{
    /* Your Code */
    init_lock(&s->lk);
    s->val = initval;
}

void
up_sem(struct sem_t *s) 
{
    /* Your Code */
    acquire_lock(&s->lk);
    s->val += 1;
    release_lock(&s->lk);
    signal_sem(&s->lk);
    
}

void 
down_sem(struct sem_t *s) 
{
    /* Your Code */
    acquire_lock(&s->lk);
    if(s->val>0){
        s->val -= 1;
       // release_lock(&s->lk);
    }
    while(s->val == 0){
       block_sem(&s->lk);
    }
    release_lock(&s->lk);
}
