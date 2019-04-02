#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/fcntl.h>

int main(int argc, char const *argv[]){
  char c;
  int fd=open("foo",O_RDONLY);
  pid_t pid;
  int why;

  for(int i=0; i<atoi(argv[1]);i++){
    pid=fork();
    
    if(pid==-1)  exit(1);
    
    else if(pid==0){   
      if(read(fd,&c,1)>0) printf("CHILD:: %c\n",c);
      exit(getpid()%10);
    }
    else{
      wait(&why);
      if(read(fd,&c,1)>0) printf("PARENT:: %c\n",c);
      else exit(1);
    }
  }
  return 0;
}
