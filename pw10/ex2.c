#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<ulimit.h>

// // void display(int Ugur){
  
// //     static int i=0;
// //     printf("  i = %d\n",i);
// //     i++;
// //     if(i==5) exit(1);
// // }
// int main(int argc, char const *argv[]){
//     printf("%d\n",getpid());
//     // signal(SIGQUIT,display);
//     while(1);
//     return 0;
// }

void handler(int sig){
    static int i=1;
    printf("   %d\n",i++);
    pid_t pid;
    pid=fork();

    if(pid==-1){
      fprintf(stderr,"Exit_1");
      exit(1);
    }
    else if(pid==0){   
      execlp("ulimit", "ulimit", "-c", "unlimited", NULL);
      fprintf(stderr,"Exit_2");
      exit(2);
    }

    if(i > 5) exit(1);
}

int main(int argc, char const *argv[]){
    printf("%d\n",getpid());
    signal(SIGQUIT,handler);
    while(1);
    return 0;
}
