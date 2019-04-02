#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char const *argv[]){
   char str1[50];
   fgets(str1,50,stdin);
   int nStdinLength = strlen(str1); 
   char *str2=(char*)malloc(nStdinLength*sizeof(char));
   strncpy(str2,str1,nStdinLength-1);
   int nStr2Length = strlen(str2); 
   puts(str2);
   printf("%d\n",nStr2Length);
   return 0;
}
