#include <sys/types.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    // wrong argument count
    if(argc != 2){
        fprintf(stderr, "Wrong argument count, expected a"
        "directory name\n");
        return -1;
    }

    // get system time
    struct timeval t;
    gettimeofday(&t, NULL);

    // save microseconds to measure ls's runtime
    time_t start = t.tv_usec;

    // print the time
    printf("System time:  secs: %lu   us: %lu\n", t.tv_sec, t.tv_usec);

    // fork and execute
    int pid = fork();
    switch (pid)
    {
        case -1:
            exit(-1);
            break;

        case 0:
            execlp("ls", "ls", "-l", argv[1], NULL);
            break;

        default:
            wait(NULL);
            gettimeofday(&t, NULL);
            printf("ls took %.3f ms to run\n", (t.tv_usec-start)/1000.0);
            break;
    }

    // display time again
    gettimeofday(&t, NULL);
    printf("System time:  secs: %lu   us: %lu\n", t.tv_sec, t.tv_usec);

    return 0;
}