#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define TRUE 1

/*
Write a C program that forks a child
process, waits for 10 seconds and then
sends a SIGTERM signal to the child
• Child process should run an infinite loop
and print “I’m alive” every second
• Hint: use kill() system call to send a signal
*/

int main()
{
    int pid;
    pid = fork();
    sleep(10);

    if (pid > 0){ //parent
        kill(pid, SIGTERM); //send signal TERM to process with id pid
    }
    else{ //child
        while (TRUE){
            printf("I'm alive");
            sleep(1);
        }
    }
    return 0;
}
