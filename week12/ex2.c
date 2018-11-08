#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <memory.h>


#define MAX_LEN 256
#define APPEND_FLAG "-a"


int main(int argc){
    char in[MAX_LEN];
    char f = 0;
    int n = argc;

    fread(in, 1, MAX_LEN, stdin);
    FILE** fout = malloc(sizeof(FILE*) * n);
    * fout = stdout;

    for (int i = 1; i < n; i++){
        if (i == 1 && !strcmp(APPEND_FLAG, argv[i])){
            f = 1;
            fout[i] = NULL;
        }
        else{
            char* mode = f ? "a" : "w";
            fout[i] = fopen(argv[i], mode);
        }
    }

    for (int i = 1; i < n; i++){
        if (!fout[i])
            continue;
        fputs(in, fout[i]);
        fclose(fout[i]);
    }
}
