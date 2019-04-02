#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include<unistd.h>

char *my_ttyname(int fd);

int main(int argc, char *argv[]) {
    printf("%s\n", ttyname(0));
    printf("%s\n", my_ttyname(1));
    printf("%s\n", my_ttyname(2));

    return 0;
}

char *my_ttyname(int fd) {
    struct stat st;
    fstat(fd, &st);
    DIR *d = opendir("/dev/pts/");
    struct dirent *dir;
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_ino == st.st_ino) {
                char *out = (char*) calloc(15, sizeof(char));
                strcpy(out, "/dev/pts/");
                strcat(out, dir->d_name);
                return out;
            }
        }
    }
}