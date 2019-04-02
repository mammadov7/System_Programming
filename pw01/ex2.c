#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct month {
char *name;/* name */
int days ; /* number of days in the month */
} Month;

int main(){
   Month array[12];
   array[0].name="January";   array[0].days=31;       
   array[1].name="February";   array[1].days=28;       
   array[2].name="March";   array[2].days=31;       
   array[3].name="April";   array[3].days=30;       
   array[4].name="May";   array[4].days=31;       
   array[5].name="June";   array[5].days=30;       
   array[6].name="July";   array[6].days=31;       
   array[7].name="August";   array[7].days=31;       
   array[8].name="September";   array[8].days=30;       
   array[9].name="October";   array[9].days=31;       
   array[10].name="November";   array[10].days=30;       
   array[11].name="December";   array[11].days=31;       
   char str[10];  int nErrorDetector=0; 
   printf("Enter name of the month like (May,April...): ");
   scanf("%s",str);
   for(int i=0;i<12;i++)
      if(!strcmp(str,array[i].name)){
         printf("It is %d mounth\n",i+1);
         printf("Number of days %d\n",array[i].days);
         nErrorDetector++;
      }
   if(!nErrorDetector)
      printf("Month not valid\n");
}