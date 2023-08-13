#include <stdio.h>
#include <stdlib.h>

int *changeArray(int * arr, int size){
    for (int i = 0; i < size; i++) {
        arr[i] = i * 3;
    }

    return arr;
}


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

    printf("\nArray before changeArray function\n");
    printf("%d\n", *(arr + 1)); // print element in index 2
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nArray after changeArray function\n");
    arr=changeArray(arr, size);
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}
