#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(int argc, char const *argv[]){
  int why;
  pid_t pid;
  pid=fork();
  if(!pid){
    printf("CHILD:: %d - id of child, %d - id of parent\n", getpid(), getppid());
    exit(getpid()%10);
  }
  else if(pid==-1)
    exit(1);
  else {
    printf("PARENT:: %d - child, %d - parent, ", pid, getpid());
    wait(&why);
    printf("child exited with status: %d\n", WEXITSTATUS(why));
  }
  return 0;
}
