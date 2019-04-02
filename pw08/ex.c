#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>
#include<sys/fcntl.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(int argc, char const *argv[]){
  struct timeval tv;
  struct timezone *tz=NULL;
  pid_t pid;  
  pid=fork();
  if(pid==-1){
    fprintf(stderr,"ERROR, exit(0)");
    exit(0);
  } else if(pid==0){
    dup2(open("/dev/null",O_WRONLY),1);
    execlp("ls","ls","-R",NULL);
  } else{
    wait(NULL);
    gettimeofday(&tv,NULL);
    printf("seconds - %lu  microseconds - %lu\n",tv.tv_sec,tv.tv_usec); exit(2);  
  }    


  return 0;
}
