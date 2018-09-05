#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 1000000


void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}


void bubble_sort(int n, int *arr){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}


int main()
{
    int n, arr[MAX_SIZE];
    scanf("%i", &n);
    for (int i = 0; i < n; i++)
        scanf("%i", &arr[i]);

    bubble_sort(n, arr);

    for (int i = 0; i < n; i++)
        printf("%i ", arr[i]);

    return 0;
}
