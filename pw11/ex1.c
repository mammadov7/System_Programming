#include<stdio.h>
#include<stdlib.h>
#include <signal.h>
#include<unistd.h>
#include <string.h>
#include<sys/fcntl.h>
#include <time.h>

unsigned long int  i=0;
int fd;
void handler(int sig){
  fd=open("foo", O_CREAT | O_WRONLY | O_APPEND , S_IRWXU);
  if(sig==SIGTERM){
    char c[]="end\n";
    write(fd,c,strlen(c));
    close(fd);
    exit(0);
  }
  if(sig==SIGINT){
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char *iBuff=(char *)malloc(100*sizeof(char));
    sprintf(iBuff,"i = %ld\t\t%s",i,asctime(tm));
    write(fd, iBuff, strlen(iBuff));
  }
}

int main(int argc, char const *argv[]){
  printf("%d\n",getpid());
  signal(SIGINT,handler);
  signal(SIGTERM,handler);
  while(1)
    i++;
  return 0;
}