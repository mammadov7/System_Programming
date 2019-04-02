#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/fcntl.h>
#include<sys/wait.h>
#define BUFF_SIZE 128

int main(int argc, char *argv[]){
  int tube[2];
  int pid;
  int tube1[2],pid1;
  if (argc!=2) {exit(3);}
  if (pipe(tube) != 0) {
    fprintf(stderr, "Cannot pipe\n");
    exit(1);
  }
  pid=fork();
  if (pid==-1) {exit(2);}
  if (pid==0){
    if(pipe(tube1)==-1) exit(3);
    pid1=fork();
    if (pid1==-1) {exit(2);}
    
    if(pid1==0){
      
    }



    close(tube[0]);
    dup2(tube[1],1);
    close(tube[1]);





  } 
  else{ 
    close(tube[1]);
    dup2(tube[0], 0);
    close(tube[0]);
  }
  return 0;
}
