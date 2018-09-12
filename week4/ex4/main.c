#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 100


void read_command(char *command){
    gets(command);
}


void next_line(){
    printf("> ");
}


int main(){
    char command[MAX_LEN];
    while (true) {
        next_line();
        read_command(command);
        system(command);
    }
    return 0;
}
