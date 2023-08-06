#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 5

/* Assignment: 3 Campus: Beer Sheva
 Author: Genady Kogan, ID: 328956537 */


//task1
int MaxSumDiagonal(int arr[][N]);
//task2
int RotateMatrix90(int arr[][N]);




int main() {

    int arr[N][N];/* = { { 1,62,3,4,5, },
				   { 6,7,8,9,10 },
				   { 11,12,13,14,15 },
				   { 16,17,18,19,20 },
				   { 21,22,23,24,25 } };*/


    printf("Enter numbers for 2D ARRAY:\n");

    for (int i = 0; i < N; i++) {
        for (int j = 0;j < N;j++) {
            printf("Enter value for disp[%d][%d]:", i, j);
            scanf("%d", &arr[i][j]);
        }
    }


    printf("\n");

    printf("Your matrix is:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0;j < N;j++) {
            printf("%4d", arr[i][j]);

        }
        printf("\n");
    }

    //call of function
    printf("\n");
    printf("Task3\n");
    MaxSumDiagonal(arr);
    printf("Task4\n");
    RotateMatrix90(arr);

    return 0;
}

//task1
int MaxSumDiagonal(int arr[][N]) {
    int diagonal, i, j, sumdiagonal = 0, max = 0, index, count = 0;

    for (diagonal = 0; diagonal < (N + N) - 1; diagonal++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if ((i + j) == diagonal) {
                    sumdiagonal += arr[i][j];
                }
            }
        }

        if (sumdiagonal > max) {
            max = sumdiagonal;
            index = diagonal;
        }

        sumdiagonal = 0;
    }

    printf("The MAX sum of diagonals: %d\n", max);

    printf("The elements of the MAX sum diagonal: ");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if ((i + j) == index) {
                printf("%d ", arr[i][j]);
            }
        }
    }
    printf("\n");

    return max;
}
//task2




int RotateMatrix90(int a[][N]) {

    int i, j;

    int b[N][N];

    // Rotating
    //printf("Your matrix is:\n");
    for (i = 0; i<N; i++) {
        for (j = 0; j<N; j++) {
            b[j][N - i - 1] = a[i][j];
            //printf("%4d", b[j][N - i - 1]);
        }
    }


    // Printing rotated matrix
    printf("After rotating:\n");
    for (i = 0; i<N; i++, printf("\n")) {
        for (j = 0; j<N; j++) {
            printf("%4d ", b[i][j]);
        }
    }
    return 0;
}
