#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void handler(int sig){
    static int i=1;
    if(i > 5) exit(1);
    printf("   %d\n",i);
    i++;
}

int main(int argc, char const *argv[]){
    signal(SIGINT,handler);
    while(1);
    return 0;
}
