#include<stdio.h>
#include<sys/fcntl.h>
#include<unistd.h>
#include <sys/stat.h>
#include<stdlib.h>
#define MAX 1000

typedef struct MYFILE{
  int fd;
  char *buff;
  int buff_size;
  int buff_i;
}MYFILE;

int fileSize(int fd){
   struct stat s;
   if (fstat(fd, &s) == -1) {
      fprintf(stderr, "fstat(%d) returned error", fd);
      return(-1);
   }
   return(s.st_size);
}

MYFILE *my_open(char *filename,char mode){
  MYFILE *new = (MYFILE*) calloc(1, sizeof(MYFILE));
  if(mode=='w'){
    new->fd=open(filename,O_CREAT | O_WRONLY | O_TRUNC , 0666);
  } else if(mode=='r'){
    new->fd=open(filename,O_RDONLY);
  } else {
      fprintf(stderr,"Error in the mode (r / w)\n");
  }
  new->buff_size=fileSize(new->fd);
  new->buff=(char *)malloc(new->buff_size*sizeof(char));
  new->buff_i=0;
  return new;
}

char my_getc(MYFILE *myfile){
  if(myfile->buff_i==0){
    read(myfile->fd,myfile->buff,myfile->buff_size);
  }
  if(myfile->buff_i<myfile->buff_size){
    return myfile->buff[myfile->buff_i++];
  }
  else return EOF;
}

void my_putc(MYFILE *myfile,char c){
  write(myfile->fd,&c,1);
  myfile->buff_size++;
  myfile->buff=realloc(myfile->buff,myfile->buff_size);
  myfile->buff[myfile->buff_size-1]=c;
}

void my_close(MYFILE *myfile){
  close(myfile->fd);
  free(myfile->buff);
}

int main(int argc, char const *argv[]){
  MYFILE *ali;
  ali = my_open("ali",'w');
  my_putc(ali,'s');
  my_close(ali);
  return 0;
}
