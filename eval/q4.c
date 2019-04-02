#include <sys/types.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
  if(argc != 2){
    fprintf(stderr, "Usage problem\n");
        return -1;
    }
  int al;  
  pid_t pid = fork();
  switch (pid){
    case -1:
      exit(-1);
      break;

    case 0:
      dup2(open("foo", O_CREAT | O_WRONLY, 0666), 1);
      execlp("ps", "ps", "eaux", NULL);
        break;

    default:
      wait(NULL);  
      int pid2 = fork();
            
      switch (pid2){
          case -1:
            exit(-1);
           break;
  
          case 0:
              dup2(open("foo", O_RDONLY), 0);
              dup2(open("/dev/null", O_WRONLY), 1);
              char arg_grep[255] = {'\0'};
              sprintf(arg_grep, "^%s ", argv[1]);
              execlp("grep", "grep", arg_grep, NULL);
              exit(0);
    
          default:
            wait(&al);
            if(WEXITSTATUS(al) == 0)
              printf("%s is connected\n", argv[1]);
          break;
      }
        
    break;   
  }
 return 0;
}