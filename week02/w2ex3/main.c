#include <stdio.h>
#include <stdlib.h>


int get_width(int height){
    return height * 2 - 1;
}


void print_triangle(int n){
    int width = get_width(n);

    for (int i = 1; i <= n; i++){
        int stars = get_width(i);
        int spaces = (width - stars) / 2;

        for (int j = 0; j < spaces; j++)
            printf(" ");
        for (int j = 0; j < stars; j++)
            printf("*");
        for (int j = 0; j < spaces; j++)
            printf(" ");

        printf("\n");
    }
}


int main(int argc, char *argv[]) //argc - count of argumetns, argv - arguments
{
    int n;
    if (argc > 1)
        sscanf(argv[1], "%i", &n);
    else
        scanf("%i", &n);

    print_triangle(n);

    return 0;
}
