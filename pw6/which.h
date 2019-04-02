#pragma once

#include <dirent.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// returns an array of strings
char** split_string(const char *string, char delim, int *tokens){
    char **res;
    int i_chars = 0, n_delims = 0, i_token = 0;
    int len = strlen(string);

    // count number of delimiters
    for(int i=0; i<len; i++){
        if(string[i] == delim)
            ++n_delims;
    }
    res = malloc(sizeof *res * (n_delims+1));

    // go until you reach end of string, write to array 
    // every time you encounter a delim char
    for(int i=0; i<=len; ++i){
        ++i_chars;
        if(string[i] == delim || string[i] == '\0'){
            res[i_token] = malloc(sizeof * res[i_token] * (i_chars+1));
            strncpy(res[i_token], &string[-i_chars+i+1], i_chars-1);
            i_chars = 0;
            ++i_token;
        }
    }

    if(tokens) *tokens = n_delims+1;
    return res;
}


void print_file_stats(char *filename){
    
    // check whether file exists
    int file=0;
    if((file=open(filename,O_RDONLY)) < -1)
        return;

    // retrieve file stats
    struct stat fileStat;
    if(fstat(file, &fileStat) < 0)
        return;

    printf( (S_ISDIR(fileStat.st_mode)) ? "d " : "f ");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");

    printf("\t%-32s\n", filename);

}

int print_if_exists(const char *dirname, const char *file){

    int ret_int = 0;
    DIR *d;
    struct dirent *dir;
    d = opendir(dirname);

    // holds absolute path to files
    char name[255] = {'\0'};

    if(d){
        while((dir = readdir(d)) != NULL){
            strcpy(name, dirname);
            strcat(name, "/");
            if(dir->d_name[0] != '.'){
                strcat(name, dir->d_name);
                if(!strcmp(dir->d_name, file)){
                    printf("%s\n", name);
                    ret_int++;
                }
            }
        }
        closedir(d);
    }

    return ret_int;
}