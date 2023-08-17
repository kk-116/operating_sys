#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
 
 void forkexample()
{
      int PID,PPID;
     PID = getpid();
     PPID = getppid();
    if(fork() == 0) {   
    printf("Child : My process ID is: %d\n",PID);   
    exit(EXIT_SUCCESS);
  }
  else if(fork() >0){ 
    wait(NULL);
    printf("Child : My parent process ID is: %d\n", PPID);
   
  }
  
}
int main(void) {
  int PID,PPID;
     PID = getpid();
     PPID = getppid();

  printf("Parent : My process ID is: %d\n",PPID);
    printf("Parent : My child process ID is: %d\n", PID);
      forkexample();
return 0;
 
}
