#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{

  pid_t c_pid = fork();
  if (c_pid == 0)
  {
    char ch;
    printf("Child : My process ID is: %d\n", getpid());
    printf("Child : My parent process ID is: %d\n", getppid());
    printf("\nChild : Check child process state\n \n");
    printf("Child : Press any key to continue\n");
    scanf("%c", &ch);
    exit(0);

  }

  else
  {
    printf("Parent : My process ID is: %d\n", getpid());
    printf("Parent : My child process ID is: %d\n", c_pid);
    sleep(60);
    printf("Child : Check child process state again\n");
    wait(NULL);
  }
}
