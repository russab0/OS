#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdlib.h>

#define TRUE 1


void sigint_notify(){
    puts("SIGNINT was recieved\n");
}


void sigusr1_notify(){
    puts("SIGUSR1 was recieved\n");
}


int main()
{;
    printf("%d", pid);
    while (TRUE){
         signal(SIGINT,  sigint_notify);
         // SIGKILL cannot be caught or ignored
         // SIGSTOP cannot be caught or ignored
         signal(SIGUSR1, sigusr1_notify);
    }
    //sleep(30);
    return 0;
}
