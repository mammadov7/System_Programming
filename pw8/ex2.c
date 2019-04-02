#include <sys/types.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
  // wrong argument count
  if(argc != 2){
      fprintf(stderr, "Wrong argument count, expected a"
      "directory name\n");
      return -1;
  }
  // will hold child process times
  struct tms t;
  int fd_null = open("/dev/null", O_WRONLY);
  // fork and execute
  int pid = fork();
  switch (pid){
    case -1:
      exit(-1);
      break;
    case 0:
      dup2(open("/dev/null", O_WRONLY), 1);
      execlp("ls", "ls", "-R", argv[1], NULL);
      break;
    default:
      wait(NULL);
      times(&t);
      printf("ls took %lu ms to run\n", t.tms_cutime+t.tms_cstime);
      break;
  }
  return 0;
}