#include <stdio.h>
#include <stdlib.h>

/*
Create a program that declares a variable
n, forks a new process and prints “Hello
from parent [PID - n]” and “Hello from
child [PID - n]” from parent and child
processes respectively. Run it 10 times
and explain the output
• Hint: to run it N times you can write a
shell script
*/

int main()
{
    int pid = fork(), n = 21;

    if (pid > 0)
        printf("Hello from parent [%d - %d]\n", pid, n);
    else
        printf("Hello from child [%d - %d]\n", pid, n);

    return 0;
}
