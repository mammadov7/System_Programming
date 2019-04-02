#include <sys/types.h>
#include <sys/times.h>
#include <sys/stat.h> 
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
    if(argc != 2){
        fprintf(stderr, "Wrong argument count," 
        " expected a user name\n");
        return -1;
    }

    int fd;
    char * myfifo = "toto";
    char arg[255] = {'\0'};
            mkfifo(myfifo, 0666);  

    int ret;
    int pid = fork();
    switch (pid){
        case -1:
            exit(-1);
            break;

        case 0:
            fd = open(myfifo, O_WRONLY); 
            dup2(fd,1);
            close(fd);

            //dup2(open("toto", O_CREAT | O_WRONLY, 0666), 1);
            execlp("ps", "ps", "eaux", NULL);
            break;
        default:
            wait(NULL);   // wait for ps
            dup2(open("toto", O_RDONLY), 0);
            dup2(open("/dev/null", O_WRONLY), 1);
            
            sprintf(arg, "^%s ", argv[1]);
            execlp("grep", "grep", arg, NULL);
            exit(0);
        break;
    }
    return 0;
}