#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_LEN 100
#define NEXT_LINE ">>> "


int main(){
    char command[MAX_LEN];
    while (true) {
        printf(NEXT_LINE);
        char *command;
        gets(command);
        system(command);
    }
    return 0;
}
