#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int convertDecimalToOctal(int decimalNumber);
int main(int argc, char const *argv[]){
   char str1[50];
   fgets(str1,50,stdin);
   int nStdinLength = strlen(str1); 
   for(int i=0;i<nStdinLength;i++){   
    if((unsigned char)str1[i]>127)
        printf("%c",str1[i]);   
    else 
      printf("%c",str1[i]);
  }
  printf("\n");