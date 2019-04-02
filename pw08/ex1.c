#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(int argc, char const *argv[]){
  struct timeval tv;
  int why;
  gettimeofday(&tv,NULL);
  time_t start=tv.tv_usec;
  printf("seconds - %lu  microseconds - %lu\n",tv.tv_sec,tv.tv_usec);
  pid_t pid=fork();
  if(pid==-1){  
    exit(1);
  } else if(!pid){  
      execlp("ls", "ls", "-l", argv[1], NULL);  exit(0);
  } else {  
    wait(&why);
    gettimeofday(&tv,NULL);
    printf("milliseconds - %.3f \n",(tv.tv_usec-start)/1000.0); exit(2);  
  }
  return 0;
}
