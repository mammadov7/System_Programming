#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  int n = 5;
  int pid[n];
  for (int i = 0; i < n; ++i) {
    pid[i] = fork();
    switch (pid[i]) {
      case -1:
        fprintf(stderr, "Something went wrong\n");
        exit(1);
      case 0:
        exit(i);
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("pid[%i]: %d\n", i, pid[i]);
  }
  int count = 0;
  do {
    int ret_val;
    printf("pid of a child: %d\n", wait(&ret_val));
    if (WIFEXITED(ret_val)) printf("Return value: %d\n", WEXITSTATUS(ret_val));
    count++;
  } while (count < n);
  return 0;
}
