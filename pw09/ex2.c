#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]){
  int tube[2],tube1[2];
  int v,v1;
  int pid,pid1;
  v=pipe(tube);
  if (v==-1) {exit(0);}
  pid=fork();
  if (pid==-1) {exit(1);}
  if (pid==0)  {
      //child "ls -l"
      v1=pipe(tube1);
      if(v1==-1) exit(3);
      pid1=fork();
      if(pid1==-1) exit(4);
      else if(pid1==0){
        //2nd child
        close(tube1[0]);
        dup2(tube1[1], 1);
        close(tube1[1]);
        execlp("ps", "ps", "eaux", NULL);
        exit(5);
      }
      else{ 
        close(tube1[1]);
        dup2(tube1[0], 0);
        close(tube1[0]);

        dup2(tube[1], 1);
        close(tube[1]);
        execlp("grep", "grep",argv[1], NULL);
        exit(6);
      }
    }
  else {
      //parent 
        close(tube[1]);
        dup2(tube[0], 0);
        close(tube[0]);
        execlp("wc", "wc", "-l", NULL);
    }
  return 0;
}