#include <sys/types.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
    if(argc != 2){
        fprintf(stderr,"Usage problem \n");
        return -1;
    }
    char arg[255] = {'\0'};
    int ret;
    int pid = fork();
    switch (pid){
        case -1:
            exit(-1);
            break;
        case 0:
            dup2(open("toto", O_CREAT | O_WRONLY, 0666), 1);
            execlp("ps", "ps", "eaux", NULL);
            break;
        default:
            wait(NULL);   // wait for child
            dup2(open("toto", O_RDONLY), 0);
            dup2(open("/dev/null", O_WRONLY), 1);
            sprintf(arg, "^%s ", argv[1]);
            execlp("grep", "grep", arg, NULL);
            exit(0);
        break;
    }
    return 0;
}