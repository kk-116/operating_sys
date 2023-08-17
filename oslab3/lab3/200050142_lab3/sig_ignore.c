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
    int a=0;
    while(a>=0){
        signal(SIGINT,SIG_IGN);
        signal(SIGTERM,SIG_IGN);
        sleep(3);
        printf("Waiting...\n");
        a++;
    }
    return 0;
}