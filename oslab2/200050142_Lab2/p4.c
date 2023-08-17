#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{

    char fname1[100], fname2[100];

    scanf("%s", fname1);
    scanf("%s", fname2);

    char *c = (char *)calloc(__INT_MAX__, sizeof(char));
    int f1o = open(fname1, O_RDONLY);
    int f1r = read(f1o, c, __INT_MAX__);

    int f2o = open(fname2, O_WRONLY | O_CREAT);
    int f2w = write(f2o, c, strlen(c));

    close(f1o);
    close(f2o);

    return 0;
}
