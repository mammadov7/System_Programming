#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(){

FILE *fp1,*fp2;
int c;

fp1=fopen("foo","r");
if(fp1==NULL)perror("fopenfoo");

fp2=fopen("bar","w");
if(fp2==NULL)perror("fopenbar");

while((c=getc(fp1))!=EOF)
if(putc(c,fp2)==EOF)perror("putc");
if(ferror(fp1))perror("getc");
if(fclose(fp1)==-1)perror("fclosefoo");
if(fclose(fp2)==-1)perror("fclosebar");

return 0;
}
