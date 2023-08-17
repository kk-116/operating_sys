#include "types.h"
#include "stat.h"
#include "user.h"

char buf[512];

void
head(int fd,int l)
{
  int n;
  int line =l;
  while((n = read(fd, buf, sizeof(buf))) > 0 && line >0) {
    int y; int s =0;
    for(y=0;y<n && line >0;y++){

      if(buf[y] == '\n'){
        line--;
        if (write(1, buf+s, y-s+1) != y-s+1 ) {
          printf(1, "head: write error\n");
          exit();
        }
        s = y+1;
      }
      
    }
  }
  if(n < 0){
    printf(1, "head: read error\n");
    exit();
  }
}

int
main(int argc, char *argv[])
{
  int fd, i;

  if(argc <= 2){
    head(0,0);
    exit();
  }

  for(i = 2; i < argc; i++){
    if((fd = open(argv[i], 0)) < 0){
      printf(1, "head: cannot open %s\n", argv[i]);
      exit();
    }
    printf(1,"------------%s------------\n",argv[i]);
    // write(1,"-----",5);
    // write(1,argv[i],sizeof(argv[i]));
    // write(1,"-----\n",6);
    head(fd,atoi(argv[1]));
    close(fd);
  }
  exit();
}
