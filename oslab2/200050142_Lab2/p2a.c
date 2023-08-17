#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int n;
	scanf("%d", &n);
	pid_t pit = fork();
	if (pit == 0)
	{
		for (int i = 1; i <= n; i++)
		{
			printf("C %d  %d\n", getpid(), i);
		}
	}
	// forkexample(n);
	else if (pit > 0)
	{
		for (int j = 1 + n; j <= 2 * n; j++)
		{
			printf("P %d  %d\n", getpid(), j);
		}
	}

	return 0;
}
