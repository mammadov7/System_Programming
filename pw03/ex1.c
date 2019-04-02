#include<stdio.h>
#include<sys/fcntl.h>
#include<unistd.h>
#define MAX 1000

int my_open(char *filename,int mode){
 int fd,fi;
  if(mode){  fi = open(filename,O_RDONLY); return fi; }
  else { fd = open(filename,O_CREAT | O_WRONLY , S_IRWXU); return fd; }
}

int main(){
  char s[MAX];
  /*int fi = open("foo.txt",O_RDONLY);
  int fd = open("bar.txt",O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
   /**/
   int fi= my_open ("foo.txt",1);
   int fd=my_open("bar.txt",0);


  printf("fd  = %d\n",fd);
  if(fi<0 || fd<0)
    printf("ERROR\n");

  while(read(fi,s,1)>0){
    write(fd,s,1);
  }

}
