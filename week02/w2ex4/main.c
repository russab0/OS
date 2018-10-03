#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main()
{
    int a, b;

    scanf("%i %i", &a, &b);
    swap(&a, &b);
    printf("%i %i", a, b);

    return 0;
}
