#include <stdio.h>
#include <stdlib.h>


int get_width(int height){
    return height * 2 - 1;
}


void print_triangle0(int n){
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


void print_triangle1(int n){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }
}


void print_triangle2(int n){
    int i = 1;
    int c = +1;
    while (i){
        for (int j = 1; j <= i; j++)
            printf("*");
        printf("\n");

        if (i > n /  2)
            c = -1;
        i += c;
    }
}


void print_square(int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            printf("*");
        printf("\n");
    }

}


int main(int argc, char *argv[]) //argc - count of argumetns, argv - arguments
{
    int n, type;
    if (argc > 2)
        sscanf(argv[1], "%i %i", &n, &type);
    else
        scanf("%i %i", &n, &type);


    switch(type){
        case 0:
            print_triangle0(n); break;
        case 1:
            print_triangle1(n); break;
        case 2:
            print_triangle2(n); break;
        case 3:
            print_square(n); break;
        default:
            printf("Unknown type\n");
    }

    return 0;
}
