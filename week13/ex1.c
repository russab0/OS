#include <stdlib.h>
#include <stdio.h>

#define true 1
#define false 0

int main(){
    FILE* fin = fopen("input.txt", "r");

    int m, proc_num;
    fscanf(fin, "%d", &m);
    fscanf(fin, "%d", &proc_num);

    int* e = malloc(sizeof(int) * m);
    int* a = malloc(sizeof(int) * m);

    for (int i = 0; i < m; i++)
        fscanf(fin, "%d", e[i]);
    for (int i = 0; i < m; i++)
        fscanf(fin, "%d", a[i]);


    int** c = malloc(sizeof(int*) * proc_num);
    for (int j = 0; j < proc_num; j++)
        c[j] = malloc(sizeof(int*) * m);
    for (int k = 0; k < proc_num; k++)
        for (int i = 0; i < m; i++)
            fscanf(fin, "%d", c[k] + i);

    int** r = malloc(sizeof(int*) * proc_num);
    for (int j = 0; j < proc_num; j++)
        r[j] = malloc(sizeof(int*) * m);
    for (int k = 0; k < proc_num; k++)
        for (int i = 0; i < m; i++)
            fscanf(fin, "%d", r[k] + i);


    char* p = malloc(sizeof(char) * proc_num);
    for (int n = 0; n < proc_num; n++)
        p[n] = false;

    while (true){
        int chosen = -1;
        for (int i = 0; chosen < 0 && i < proc_num; i++){
            fflush(stdout);
            if (p[i])
                continue;

            int all = 1;
            for (int j = 0; j < m && all; j++)
                if (a[j] < r[i][j])
                    all = 0;
            if (all)
                chosen = i;
        }
        if (chosen == -1)
            break;

        p[chosen] = true;
        for (int i = 0; i < m; i++)
            a[i] += c[chosen][i];
    }


    int marked = 1;
    for (int l = 0; l < proc_num && marked; l++)
        marked = p[l];
    if (marked){
        FILE* fout = fopen("output_ok", "w+");
        fprintf(fout, "There if no deadlock");
    }
    else{
        FILE* fout = fopen("output_dl", "w+");
        fprintf(fout, "Deadlock found, processes:\n");
        for (int i = 0; i < proc_num; i++)
            if (!p[i])
                fprintf(fout, "%d ", i + 1);
    }
}
