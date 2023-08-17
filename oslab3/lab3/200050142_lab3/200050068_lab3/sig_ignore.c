#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
    //if(fork() == 0) {   
    int pid = getpid();
    printf("Process Id is : %d\n",pid);//}
    int i=0;
    while(i>=0){
        signal(SIGTERM,SIG_IGN);
        signal(SIGINT,SIG_IGN);
        sleep(3);
        printf("Waiting...\n");
        i++;
    }
    return 0;
}