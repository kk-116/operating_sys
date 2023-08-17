#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd1[2];
    int fd2[2];
    int valA;
    int valB;
    int valC;

    // create pipe descriptors
    pipe(fd1);
    pipe(fd2);
    // fork() returns 0 for child process, child-pid for parent process.
    if (fork() != 0)
    {
        // A -> B
        //  parent: writing only, so close read-descriptor.
        close(fd1[0]);
        close(fd2[0]);
        // send the value on the write-descriptor.
        scanf("%d", &valA);
        // send the value on the write-descriptor.
        scanf("%d", &valB);
        write(fd1[1], &valA, sizeof(valA));
        printf("Process A : Input value of x : %d\n", valA);
        printf("Process B : Input value of y : %d\n", valB);

        // close the write descriptor
        close(fd1[1]);

        // B -> C

        valC = valB + valA;
        write(fd2[1], &valC, sizeof(valC));
        // printf("B(%d) send value: %d\n", getpid(), valB);
        close(fd2[1]);
    }
    else
    { // child: reading only, so close the write-descriptor
        close(fd1[1]);
        close(fd2[1]);
        // now read the data (will block)
        read(fd1[0], &valA, sizeof(valA));
        // printf("B(%d) received value: %d\n", getpid(), valA);
        read(fd2[0], &valC, sizeof(valC));
        // printf("C(%d) received value: %d\n", getpid(), valB);
        printf("Process C : Result after addition : %d\n", valC);

        // close the read-descriptor
        close(fd1[0]);

        close(fd2[0]);
    }
    return 0;
}