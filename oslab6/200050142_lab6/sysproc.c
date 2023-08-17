#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_helloYou(void)
{
  char *n;
  argstr(0,&n);
  return helloYou(n);
}

int sys_wait2(int *wtime, int *runtime)
{
  int* a;
  int* b;
  argptrint(0, &a);
  argptrint(1, &b);
  return wait2(a, b);
}

int
sys_getNumProc(void)
{
  return getNumProc();
}

int
sys_getMaxPid(void)
{
  return getMaxPid();
}

int
sys_numOpenFiles(void)
{
  return numOpenFiles();
}

int
sys_csinfo(void)
{
  return csinfo();
}

int
sys_freememstat(void)
{
  return freememstat();
}

void
sys_getmeminfo(void)
{
  int pi;
  argint(0, &pi);
  getmeminfo(pi);
  return;
}

int
sys_cps(void)
{
  return cps();
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_mmap(void)
{

  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  if(n%4096 != 0 || n<0)
    return 0;

  addr = myproc()->sz;
  myproc()->sz += n;
  
  return addr;
  
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
