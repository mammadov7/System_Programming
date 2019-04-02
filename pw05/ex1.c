#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc, char const *argv[]){
  if(argc != 2){
    printf("You should write file name");
    return 1;
  }
  struct stat fileStat;

  if(stat(argv[1],&fileStat) < 0)    
    return 1;
  
  printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\t%s\n",argv[1]);  
  return 0;
}
