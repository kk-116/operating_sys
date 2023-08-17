#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>

int main(int argc, char *argv[])
{
    pid_t pid1 = atoi(argv[1]);

    kill(pid1,SIGINT);
    printf("SIGINT signal sent to PID: %d\n",pid1);
    kill(pid1,SIGTERM);
    printf("SIGTERM signal sent to PID: %d\n",pid1);
    kill(pid1,SIGKILL);
    printf("SIGKILL signal sent to PID: %d\n",pid1);

    return 0;
}
