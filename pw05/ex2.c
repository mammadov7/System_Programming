#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
#include <dirent.h>

void perm(char *filename){
  struct stat fileStat;
  if(stat(filename,&fileStat) < 0 || filename[0]=='.' )    
    return;
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
    printf("\t%s\n",filename);
}

int main(int argc, char const *argv[]){
  if(argc!=2)
    return 1;
  DIR *dir;
  struct dirent *dent; 
  dir=opendir(argv[1]);
  if(dir!=NULL)
  while((dent=readdir(dir))!=NULL){
      perm(dent->d_name); 
  }
  return 0;
}
