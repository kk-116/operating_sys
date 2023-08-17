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
    pid_t p = atoi(argv[1]);

    kill(p,SIGINT);
    printf("SIGINT signal sent to PID: %d\n",p);
    kill(p,SIGTERM);
    printf("SIGTERM signal sent to PID: %d\n",p);
    kill(p,SIGKILL);
    printf("SIGKILL signal sent to PID: %d\n",p);

    return 0;
}
