#include <stdlib.h>
#include <stdio.h>

#include "which.h"


int main(int argc, char *argv[]){

    // check argument count
    if(argc != 2){
        printf("Wrong argument count\n");
        return 1;
    }

    char *path = getenv("PATH");
    int num_strings = 0;
    char **s =  split_string(path, ':', &num_strings);
    int num_found = 0;

    for(int i=0; i<num_strings; i++){
        num_found += print_if_exists(s[i], argv[1]);
    }

    if(num_found == 0)
        printf("No matches have been found for %s\n", argv[1]);

    return 0;
}