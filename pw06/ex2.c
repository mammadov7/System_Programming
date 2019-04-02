#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>

char **strToArr(char *str,int *size);


int main(int argc, char const *argv[]){
  int size;
  const char *name = "PATH";
  char *value;
  char **x;
  value = getenv(name);
  x=strToArr(value,&size);
 
  for(int i=0;i<=size;i++){


  return 0;
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
  *arrOfStr=(char *)calloc(nMaxChDr,sizeof(char));
  pch = strtok (str,"/");
  while (pch != NULL){
    arrOfStr[k]=pch;;
    pch = strtok (NULL, "/");
    k++;
  }
  *size=nNbOfDir;
  return arrOfStr;
}