#include <dirent.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* my_ttyname(int fd){
    struct stat stats;

    char *dirname = "/dev/pts";
    DIR *d;
    struct dirent *dir;
    d = opendir(dirname);
    char found = 0;

    // holds absolute path to files
    char *name = malloc(sizeof * name * 255);

    // get stats about fd
    if (fstat(fd, &stats) >= 0){
        // printf("DEBUG: \t file   : %-32d\n", fd);
        // printf("DEBUG: \t st_dev : %-32lu\n", stats.st_dev);
        // printf("DEBUG: \t st_ino : %-32lu\n", stats.st_ino);
        if(d){
            while((dir = readdir(d)) != NULL){
                // printf("DEBUG: searching: [ %-12s  inode: %lu ]\n", dir->d_name, dir->d_ino);
                if(dir->d_ino == stats.st_ino){
                    strcpy(name, dirname);
                    strcat(name, "/");
                    strcat(name, dir->d_name);
                    found = 1;
                    // printf("found: \t %s \t [inode: %lu]\n", name, stats.st_ino);
                }
            }
            closedir(d);
        }
        if(found) return name;
        else return NULL;
    }
    else return NULL;
}


int main(int argc, char *argv[]){

    // check argument count
    if(argc != 2){
        printf("Wrong argument count, expected one argument: file descriptor\n");
        return 1;
    }
    
    // int fd = open(argv[1], O_RDONLY);
    // printf("DEBUG: opened file descriptor: %d\n", fd);

    char *nm = my_ttyname(atoi(argv[1]));
    
    if(nm == NULL)
        printf("Couldn't find anything\n");
    else
        printf("fd: %d  ->  %s\n", atoi(argv[1]), nm);

    return 0;
}