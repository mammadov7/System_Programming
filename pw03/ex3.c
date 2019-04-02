#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define MAX 100
static int i=0,r=0;
char buff[MAX];

char getchar_(){
  if(i==0){
  r=read(1,buff,MAX); 
  }
  if(r>i)  return buff[i++];
  else  exit(0);
}

int main(){
  printf("%c\n",getchar_());
}