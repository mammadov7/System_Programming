#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>


void display(int Ughur){
    psignal(Ugur, "Definition ");
}

int main(int argc, char const *argv[]){
  printf("%d\n" , getpid() );
  for(int i=0;i<64;i++){
    signal(i,display);
  }
  while(1);
  return 0;
}
