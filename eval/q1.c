#include <sys/types.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
  int tube[2];
  int v;
  pid_t pid;
  char name[255];
  v=pipe(tube);
  if(v==-1) { exit(5); }
  pid=fork();

  if(pid==-1){  exit(0); }

  if(pid==0){
    close(tube[0]);
    dup2(tube[1], 1);
    close(tube[1]);
    execlp("ps","ps","eaux",NULL);
    exit(1);
  }
  else{
    close(tube[1]);
    dup2(tube[0], 0);
    close(tube[0]);
    sprintf(name,"^%s ",argv[1]);
    execlp("grep","grep",name,NULL);
    exit(2);
  }
  return 0;
}
