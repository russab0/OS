#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1000000

int main()
{
    char str[MAX_LEN];

    printf("I am promting you to enter some string:\n");
    gets(str);

    int n = strlen(str);
    for (int i = n - 1; i >= 0; i--){
       printf("%c", str[i]);
    }

    return 0;
}
