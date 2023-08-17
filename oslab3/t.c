#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void sig_handler(int signum)
{

    printf("Received signal %d\n", signum);
}

int main()

{

    signal(SIGINT, sig_handler);
    sleep(30); // This is your chance to press CTRL-C
    printf("szdfdxgf");
    return 0;
}