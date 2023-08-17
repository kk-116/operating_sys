#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]){
   
        int pid =  fork();
        if(pid < 0){
            printf(1,"child process is not created\n");
        }
        else if(pid == 0){
            exec(argv[1] , argv+1);
            exit();
        }    
        else{
            wait();
            exit();
        }    
    
    return 0;
}