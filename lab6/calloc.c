#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int size = 5;

    arr = (int *)calloc(size, sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = i * 2;
    }

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}
