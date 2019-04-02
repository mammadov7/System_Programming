#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(int argc, char const *argv[]){
  pid_t pid;
  int why;
  for(int i=0; i<atoi(argv[1]);i++){
    pid=fork();
    if(!pid)   exit(getpid()%10);
    
    else if(pid==-1)  exit(1);
  
    else{
      printf("PARENT:: %d - child, %d - parent, ", pid, getpid());
      wait(&why);
      printf("child exited with status: %d\n", WEXITSTATUS(why));
    }
  }
  return 0;
}