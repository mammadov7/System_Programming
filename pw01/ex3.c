#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int convertDecimalToOctal(int decimalNumber);
int main(int argc, char const *argv[]){
   char str1[50];
   fgets(str1,50,stdin);
   int nStdinLength = strlen(str1); 

  for(int i=0;i<nStdinLength;i++){   
    if((unsigned char)str1[i]<=31 && (unsigned char)str1[i]>=0){
      if((unsigned char)str1[i]==9)
        printf("\\t");
      else if((unsigned char)str1[i]==10)
        printf("\\n");
      else if((unsigned char)str1[i]==13)
        printf("\\r");
      else if((unsigned char)str1[i]==8)
        printf("\\b");
      else
        printf("\\%o",str1[i]);
    }
    else if((unsigned char)str1[i]>127)
        printf("\\%o",str1[i]);   
    else 
      printf("%c",str1[i]);
  }
  printf("\n");
   return 0;
}
