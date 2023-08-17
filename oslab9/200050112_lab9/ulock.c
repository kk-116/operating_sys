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
    while(xchg(&s->locked, 1) != 0)
        ;
    __sync_synchronize();
}

void
release_lock(struct lock_t *s) 
{
    /* Your Code */
    __sync_synchronize();
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
    s->val++;
    signal_sem(&s->lk);
    release_lock(&s->lk);
}

void 
down_sem(struct sem_t *s) 
{
    /* Your Code */
    acquire_lock(&s->lk);
    while(s->val == 0){
        block_sem(&s->lk);
    }
    if(s->val > 0){
        s->val--;
        release_lock(&s->lk);
    }
}
