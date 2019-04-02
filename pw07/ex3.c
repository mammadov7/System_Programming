#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/fcntl.h>

int main(int argc, char const *argv[]){
  char c;
  
  pid_t pid;
  pid=fork();
  int fi=open(argv[1],O_RDONLY);
  
  switch (pid)
  {
    case -1:
      exit(0);
    break;

    case 0:
      while(read(fi,&c,1)>0) printf("CHILD: %c  ",c); 
    break;

    default:
      while(read(fi,&c,1)>0) printf("PARENT: %c  ",c);
    break;
  }


  return 0;
}
