#include <stdio.h>
#include <stdlib.h>

#define MAXN 100

main()
{

    int pid, p[2];
    char str1[MAXN] = "I love 0S";
    char str2[MAXN] = "";


    pipe(p);
    pid = fork();


    if (pid > 0) // parent
        write(p[1], str1, MAXN);
    else{ // child
        read(p[0], str2, MAXN);
        printf("str2 = '%s'\n", str2);
    }

    return 0;
}
