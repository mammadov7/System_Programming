#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#define MAX_SIZE 10000
int main(int argc, char *argv[]) {
  int x; int nNumOfLines=0; char *filename;int fromLine;
  while((x=getopt(argc,argv,"f:n:"))!=-1){
        switch(x){
            case 'f':
                filename=argv[optind-1];
            break;
            case 'n':
                fromLine=atoi(argv[optind-1]);
            break;
            default:
                printf("Getopt");
       }
    }
	FILE *file = fopen(filename, "r");
  while (!feof(file)){
    int t = fgetc(file);
    if ('\n' == t) 
			nNumOfLines++;
  }	nNumOfLines++;
   printf("%d",nNumOfLines);
  fseek(file,0,SEEK_SET);
	int copy_characters = 0;
	int line_number = 1;
	const int desired_line = nNumOfLines-fromLine+1;

	for (;;) {
		int c = fgetc(file);
		if (EOF == c)
			break;
    else if ('\n' == c) {
			line_number++;
			if (desired_line <= line_number) {
				copy_characters = 1;	printf("\n");
			} 
      else if (copy_characters) {
				break;
			}
		} 
    else if (copy_characters) {
			printf("%c",c);
		}
	}
	printf("\n");
	fclose(file);
	return 0;
}