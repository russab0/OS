#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++){
        arr[i] = i;
        printf("%i\n", arr[i]);
    }

    free(arr);

    return 0;
}
