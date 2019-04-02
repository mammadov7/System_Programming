#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 100;

char *reformat_string(char *str) {
    size_t len = strlen(str);
    char *new_str = (char*) calloc(len, sizeof(char));
    int count = 0;
    for (int i = 0; i < len; i++) {
        if ((str[i] > 31 && str[i] < 127) && str[i] != 92) {
            new_str[count++] = str[i];
        } else if (str[i] == 92) {
            i++;
            if (str[i] == 't') {
                new_str[count++] = '\t';
            } else if (str[i] == 'n') {
                new_str[count++] = '\n';
            } else if (str[i] == 'r') {
                new_str[count++] = '\r';
            } else if (str[i] == 'b') {
                new_str[count++] = '\b';
            } else if (str[i] == 92) {
                new_str[count++] = 92;
            }
        }
    }
    new_str[count] = '\0';
    return new_str;
}

int main(int argc, char *argv[]) {
    char str[MAX];
    printf("String: ");
    fgets(str, MAX, stdin);
    char *new_str = reformat_string(str);

    printf("String: %s\n", new_str);

    free(new_str);
    return 0;
}