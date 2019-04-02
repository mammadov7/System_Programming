#include<stdio.h>
#include<sys/fcntl.h>
#include<unistd.h>
#define MAX 1000

char getchar_(){
  char c;
  if(read(1,&c,1)<=0) return EOF;
  else return c;
}

int main(){
  int c  = getchar_();
  printf("%c\n",c);
}