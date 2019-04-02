#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(){

int fd1,fd2;
char c; size_t n;

fd1=open("foo",O_RDONLY);
if(fd1==-1)perror("openfoo");

fd2=open("bar",O_WRONLY|O_CREAT|O_TRUNC,0666);
if(fd2==-1)perror("openbar");

while((n=read(fd1,&c,1))>0)
if(write(fd2,&c,1)==-1)perror("write");
if(n==-1)perror("read");
if(close(fd1)==-1)perror("closefoo");
if(close(fd2)==-1)perror("closebar");

return 0;}
