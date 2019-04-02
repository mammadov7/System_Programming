#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>
#include<sys/fcntl.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(int argc, char const *argv[]){
  struct timeval tv;
  int why;
  struct timezone *tz=NULL;
  pid_t pid=fork();

  if(pid==-1)  exit(1);
  else if(!pid){  
    int fd=open("/dev/null",1);
    dup2(fd,1);
    execlp("ls", "ls", "-R", argv[1], NULL);  
    exit(0);  
  }
  else {  
    wait(&why);
    gettimeofday(&tv,NULL);
    printf("seconds - %lu  microseconds - %lu\n",tv.tv_sec,tv.tv_usec); exit(2);  
  }
  return 0;
}
  