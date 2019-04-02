#include<stdio.h>
#define MAX 1000
int main(){
  // char buffer[MAX];int i=0;
  // FILE* foo = fopen("foo.txt","r");
  // while(!feof(foo))
  //   buffer[i++]=getc(foo);
  // fclose(foo);
  
  FILE* bar = fopen("bar.txt","w");
  printf("%c\n",getc(bar));
  printf("%c\n",getc(bar));
 

  // for(int j=0;j<i-1;j++)
  //   putc(buffer[j],bar);
  fclose(bar);
}
