#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
 #include <time.h>
     
clock_t start, end;
double cpu_time_used;
int account_balance = 0;
pthread_mutex_t lock;
int deposit ;

void* increment() {
    pthread_mutex_lock(&lock);
    for(int i = 0; i < deposit; i++) {
        account_balance++;
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(int argc, char* argv[]) {
    start = clock();
    // for(int j=2;j<2048;j=j*2){
        int threadNum;
        // threadNum = j;
        threadNum = atoi(argv[1]);
        deposit = 2048*1000000/threadNum;
        pthread_t th[threadNum];
        int i;
        for (i = 0; i < threadNum; i++) {
            if (pthread_create(th + i, NULL, &increment, NULL) != 0) {
                perror("Failed to create thread");
                return 1;
            }
            printf("Transaction %d has started\n", i);
        }
        for (i = 0; i < threadNum; i++) {
            if (pthread_join(th[i], NULL) != 0) {
                return 2;
            }
            printf("Transaction %d has finished\n", i);
        }
        printf("Account Balance is : %d\n", account_balance);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Time spent: %f ms\n",cpu_time_used);
    // }
    return 0;
}