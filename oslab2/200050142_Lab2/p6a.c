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
    printf("Child : My process ID is: %d\n", getpid());
    printf("Child : My parent process ID is: %d\n", getppid());

    sleep(5);
    printf("Child : After sleeping for 5 seconds\n");
    printf("Child : My process ID is: %d\n", getpid());
    printf("Child : My parent process ID is: %d\n", getppid());
  }

  else
  {
    printf("Parent : My process ID is: %d\n", getpid());
    printf("Parent : My child process ID is: %d\n", c_pid);
    exit(0);
  }
}
