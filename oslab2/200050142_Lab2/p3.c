#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
    while(1){
        printf(">>>");
        char a[100];
        scanf("%s",a);

        pid_t pid =  fork();
        
        if(pid == 0){
            char *args[] = {a, NULL};
            execv(args[0] , args);
            exit(0);
        }    
        if(pid >0){
            wait(NULL);
        }    
    }

    return 0;
}