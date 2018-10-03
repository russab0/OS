#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>


int main()
{
    int i;
    float f;
    double d;

    i = INT_MAX;
    f = FLT_MAX;
    d = DBL_MAX;

    printf("Size Value\n");
    printf("%i    %i\n", sizeof(i), i);
    printf("%i    %f\n", sizeof(f), f);
    printf("%i    %f\n", sizeof(d), d);

    //discussing the results

    return 0;
}
