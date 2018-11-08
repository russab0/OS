#include <stdio.h>
#include <stdlib.h>

#define STR_LEN 20

int main(void) {
    FILE *fin = fopen("/dev/random", "r");
    FILE *fout = fopen("ex1.txt", "w");

    char str[STR_LEN + 1];
    fgets(str, STR_LEN + 1, fin);

    fputs(str, fout);
    close(fout);

    return 0;
}
