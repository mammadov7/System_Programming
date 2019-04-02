#include<stdio.h>
#include<sys/fcntl.h>
#include<unistd.h>
#define MAX 1000


typedef struct{
  int file;
  int mode; 
}MY_FILE;


void my_close(size_t file){
  close(file);
}

int my_open(char *filename,int mode){
  int fd,fi;
  if(mode){  fi = open(filename,O_RDONLY); return fi; }
  else { fd = open(filename,O_CREAT | O_WRONLY , S_IRWXU ); return fd; }
}

char my_getc(char *filename){
  static char buf[MAX];
  static int x=0,i=0;
  int fd = my_open(filename,1);
   read(fd,buf,MAX);
  return buf[i++];
}


char my_putc(char ch,char *filename){
  static int x=0,i=0;
  int fd = open(filename,O_CREAT | O_WRONLY | O_APPEND, S_IRWXU );
  write(fd,&ch,1);
  my_close(fd);
}

int main(int argc, char const *argv[]){




  my_putc('a',"foo.txt");   my_putc('a',"foo.txt");
  my_putc('a',"foo.txt");  my_putc('a',"foo.txt");



  printf("%c\n",my_getc("foo.txt"));
  printf("%c\n",my_getc("foo.txt"));
  printf("%c\n",my_getc("foo.txt"));
    printf("%c\n",my_getc("foo.txt"));



  return 0;
}
