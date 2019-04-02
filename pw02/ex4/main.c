#include<stdio.h>
#include"area.c"
#include"perimeter.c"
#include"pi.h"

int main(int argc, char const *argv[]){

  float area1 = area(5);
  float perimeter1 = perimeter(5);

  printf("Area is: %f\nPerimeter is: %f\n",area1,perimeter1);

  return 0;
}
