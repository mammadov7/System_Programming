#include<stdio.h>
#include<sys/fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#define MAX 5

char getchar_(char c){
  if(read(1,&c,1)<=0) return EOF;
  else return c;
}

char getchar__(){
  static char buf[MAX];
  static int x=0,i=0;
    if((x=read(1,buf,MAX))<=0) return EOF;
    if(i<x) 
      return buf[i++];
    else {
      i=0;x=0;
      buf[0]='\0';
    }
}

int main(){
  printf("%c\n",getchar__());
  printf("%c\n",getchar__());
  

}