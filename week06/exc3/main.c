#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define TRUE 1

void notify(){
    puts("You have pressed Ctrl+C (SIGNINT was recieved)\n");
}

int main()
{
    while (TRUE){
         signal(SIGINT, notify);
    }
    return 0;
}
