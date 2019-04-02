#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/fcntl.h>
#include<sys/wait.h>
#define BUFF_SIZE 128

void copy(int fdsrc,int fddst){
  char buff[BUFF_SIZE]; 
  int rd;
  while((rd=read(fdsrc,buff,BUFF_SIZE))>0)
    write(fddst,buff,rd);
}

int main(int argc, char const *argv[]){
  
  copy(0,1);

  return 0;
}
