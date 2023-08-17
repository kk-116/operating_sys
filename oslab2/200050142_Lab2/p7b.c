#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void forkexample(int n)
{
	for (int i = 0; i < n; i++)
	{
		pid_t pid = fork();
		if (pid == 0)
		{
			printf("Child %d is created\n", getpid());
			sleep(1);
			printf("Child %d of parent %d exited\n", getpid(), getppid());
			exit(0);
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
	forkexample(n);
	pid_t wpid;
	int status = 0;
	while ((wpid = wait(&status)) > 0)
		;
	printf("Parent exited\n");
	return 0;
}
