#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


size_t min(size_t a, size_t b){
    if (a < b)
        return a;
    return b;
}


int* my_realloc(int* old_ptr, size_t new_size){
    int* new_ptr = malloc(new_size);

    size_t old_size = malloc_usable_size(old_ptr) / 4;
    new_size /= 4;

    if (old_ptr == NULL)
        return new_ptr;
    if (new_size == 0){
        free(old_ptr);
        return NULL;
    }


    for (int i = 0; i < min(old_size, new_size); i++)
        new_ptr[i] = old_ptr[i];

    for (int i = old_size; i < new_size; i+=1)
        new_ptr[i] = 0;

    free(old_ptr);

    return new_ptr;
}


int main()
{
    int init_size = 10;

    int* arr = malloc(init_size * sizeof(int));
    for (int i = 0; i < init_size; i++)
        arr[i] = i;

    int* arr2 = my_realloc(arr, 13 * sizeof(int));
    for (int i = 0; i < 13; i++)
        printf("%d ", arr2[i]);

    return 0;
}
