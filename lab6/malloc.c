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
    // Why we need check if arr == NULL:
    // 1. Insufficient Memory: The most common reason is that there might not be enough available memory in the system to fulfill the requested allocation. If this happens, the memory allocation function will return NULL.
    // 2. Memory Fragmentation: Over time, memory can become fragmented, meaning that there might be enough total free memory, but it's not contiguous. In such cases, a large enough block of contiguous memory might not be available even though the total free memory is sufficient.
    // 3. System Limitations: Operating systems impose limitations on the amount of memory a process can allocate. If your requested memory exceeds these limitations, the allocation will fail.
    // 4. Memory Leaks: If you don't check for NULL and proceed to use the returned pointer without verifying its validity, you might end up with a memory leak. This means that the allocated memory cannot be accessed or freed, leading to wasted memory resources.
    // 5. Unpredictable Behavior: If you attempt to use a NULL pointer, your program is likely to crash or exhibit undefined behavior. This can lead to difficult-to-debug issues, making your program unreliable.
    // 6. Robust Error Handling: Checking for NULL and handling memory allocation failures gracefully demonstrates robust error handling in your code. It allows you to catch and handle errors early, making your program more reliable and easier to maintain.
    // 7. Debugging and Maintenance: If your code doesn't handle memory allocation failures, tracking down the root cause of crashes or unexpected behavior can be challenging. Proper error handling makes debugging and maintaining your code much easier.
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
