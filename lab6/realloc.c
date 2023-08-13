#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int size = 5;

    arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = i * 2;
    }

    printf("Original array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    int new_size = 10;
    int *new_arr = (int *)realloc(arr, new_size * sizeof(int));
    if (new_arr == NULL) {
        printf("Memory reallocation failed.\n");
        free(arr);
        return 1;
    }

    for (int i = size; i < new_size; i++) {
        new_arr[i] = i * 3;
    }

    printf("\nNew array elements: ");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", new_arr[i]);
    }

    free(new_arr);
    return 0;
}



//int main()
//{
//    int *ptr,i;
//
//    //allocating memory for only 1 integer
//    ptr = malloc(sizeof(int));
//
//    ptr[0] = 1;
//
//    //realloc memory size to store 3 integers
//    ptr = realloc(ptr, 3 * sizeof(int));
//    ptr[1] = 2;
//    ptr[2] = 3;
//
//    //printing values
//    for(i = 0; i < 3; i++)
//        printf("%d\n",ptr[i]);
//
//    return 0;
//}
