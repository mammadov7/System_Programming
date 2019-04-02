#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void copy(int in, int out);

int main(int argc, char *argv[]) {
    int n = 10;
    int pipes[n][2];
    int pids[n];
    for (int i = 0; i < n; i++) {
        if (pipe(pipes[i]) != 0) {
            fprintf(stderr, "Cannot pipe(%d)\n", i);
        }
        pids[i] = fork();
        if (pids[i] == -1) {
            fprintf(stderr, "Cannot fork(%d)\n", i);
            exit(-(i + 1));
        } else if (pids[i] != 0) {
            if (i == 0) {
                dup2(pipes[i][0], 0);
            }
            close(pipes[i][0]);
            if (i == n - 1) {
                dup2(pipes[i][1], 1);
            }
            close(pipes[i][1]);
            copy(0, 1);
        } else if (i == 0) {
            close(pipes[i][0]);
            if (i == n - 1) {
                dup2(pipes[i][1], 1);
                close(pipes[i][1]);
            }

            if (i == 0) {
                copy(0, 1);
            } else if (i == n - 1) {
                copy(0, 1);
            } else {
                copy(0, 1);
            }
            exit(0);
        }
    }

    return 0;
}

void copy(int in, int out) {
    ssize_t read_n;
    char c;
    while ((read_n = read(in, &c, 1)) > 0) {
        write(out, &c, 1);
    }
}