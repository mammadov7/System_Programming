#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>

char **strToArr(char *str,int *size);

int main(int argc, char const *argv[]){
  int size;
  // const char *name = "PATH";
  char *value;
  char **x;
  value = getenv("PATH");
  x=strToArr(value,&size);

  for(int i=0;i<=size;i++){
   DIR *d=opendir(x[i]);
   struct dirent *dir;
   if(d)
     while((dir = readdir(d)) != NULL)
       if(!strcmp(dir->d_name,argv[1]))
         printf("%s/%s\n",x[i],argv[1]);
  }//end for 

}

char **strToArr(char *str,int *size){
  int i=0,nNbOfDir=0,nMaxChDr=0,j=0,k=0;
  char *pch;
  while(str[i]!='\0'){
    if((unsigned char)str[i]==(unsigned char)':'){
      nNbOfDir++;
      if(j>nMaxChDr)  nMaxChDr=j;
      j=0;
    }
    j++;  i++;
  }
  
  char **arrOfStr=(char **)calloc(nNbOfDir,sizeof(char*));
  for(int i=0;i<nNbOfDir;i++)
    arrOfStr[i]=(char *)calloc(nMaxChDr,sizeof(char));
  pch = strtok (str,":");
  while (pch != NULL){
    arrOfStr[k]=pch;;
    pch = strtok (NULL, ":");
    k++;
  }
  *size=nNbOfDir;
  return arrOfStr;
}