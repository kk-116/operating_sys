#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


void forkexample(int n,int m)
{
	if (n == 0)
	{
		return;
	}
	if (n > 0)
	{
		pid_t pid = fork();
		if (pid == 0)
		{
			printf("Child %d is created\n", getpid());
			forkexample(n - 1,m);
		}
		else
		{
			wait(NULL);
			printf("Child %d of parent %d exited\n", pid, getpid());
			if (n == m)
			{
				printf("Parent exited\n");
			}
		}
	}
	return;
}
int main(void)
{
	
	int n;
	scanf("%d", &n);
	printf("Parent  is: %d\n", getpid());
	printf("Number of children is : %d\n", n);
	forkexample(n,n);

	return 0;
}
