#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#define size 80
enum boolean { FALSE = 0, TRUE };
//declaration of function
void print(int start, int end, int skip);
int fixstr(char *);
int CheckSmall(char *);
int CheckOneNum(char *);
long CountOddRecursive(long);
int MinusPlus(int *, int);
int FibonacciCheck(int* , int );
int main() {
	int numprob;

	//menu
	printf("\tChoose the option:\n");
	printf("1  - Task-1\n");
	printf("2  - Task-2\n");
	printf("3  - Task-3\n");
	printf("4  - Task-4\n");
	printf("5  - Task-5\n");
	printf("6  - Task-6\n");
	printf("7  - Task-7\n");
	printf("8 - Exit\n");
	printf("\n");
	printf("\tYour choose is:---> ");
	scanf("%d", &numprob);
	printf("\n");
	do {
		//-------------
		if (numprob == 1) {

			int start, end, skip;
            printf("Enter start number:---> ");
            scanf("%d", &start);
            printf("Enter end number:---> ");
            scanf("%d", &end);
            printf("Enter skip number:---> ");
            scanf("%d", &skip);

            printf("Printing sequence:\n");
            print(start, end, skip);

		}//if 1
		 //-------------
		else if (numprob == 2) {

			char str[size];
			int len;
			printf("Enter string:---> ");
			getchar();
			fgets(str, size - 1, stdin);
			len = strlen(str);
			if (len > 0 && str[len + 1] == '\n')
				str[len - 1] = '\0';
			fixstr(str);


		}//else if 2
		 //-------------
		else if (numprob == 3) {

			char str[size];
			int newres, len;

			printf("Enter a string:---> ");
			getchar();
			fgets(str, size - 1, stdin);
			len = strlen(str);
			if (len > 0 && str[len + 1] == '\n')
				str[len - 1] = '\0';


			newres = CheckSmall(str);
			printf("%d", newres);
		}//else if 3
		 //-------------
		else if (numprob == 4) {

			char str[size];
			int len;
			printf("Enter string:---> ");

			getchar();
			fgets(str, size - 1, stdin);
			len = strlen(str);
			if (len > 0 && str[len + 1] == '\n')
				str[len - 1] = '\0';
			printf("%d", CheckOneNum(str));

		}//else if 4
		 //-------------
	else if (numprob == 5) {
		int *arr, arrsize;
printf("Enter amount of nubmetr:---> ");
scanf("%d", &arrsize);
arr = (int*)malloc(sizeof(int)*arrsize);
if (arr == NULL) {
	printf("Error! Not enough memmory");
	exit(1);
	}
for (int i = 0;i < arrsize;i++) {
	printf("Enter [%d] number: ---> ", i + 1);
	scanf("%d", &arr[i]);
}
printf("%d", FibonacciCheck(arr, arrsize));
free(arr);
		}//else if 5
		 //-------------
		else if (numprob == 6) {
			int size6;
			int *arr6 = NULL;
			printf("Enter size of array:---> ");
			scanf("%d", &size6);
			arr6 = (int*)malloc(sizeof(int)*size6);
			for (int i = 0;i < size6;i++) {
				printf("Enter [%d] number:---> ", i + 1);
				scanf("%d", &arr6[i]);
			}
			printf("%d", MinusPlus(arr6, size6));
			free(arr6);
		}
		//-------------
		else if (numprob == 7) {
		long num;
				printf("Enter a number:---> ");
				scanf("%ld", &num);
				printf("Result is:---> %ld\n", CountOddRecursive(num));
				
		}


		if (numprob != 8) {
			printf("\n");
			printf("Choose another function: ");
			scanf("%d", &numprob);
			printf("\n");
		}//if 6



	} while (numprob != 8); //do
	printf("\n");
	printf("Have a nice day.");
	printf("\n");

	return 0;
}
//---------------------------task1-----------------------------
void print(int start, int end, int skip) {

    if (start <= end) {
        printf("%d\n", start);
        print(start + skip, end, skip);
    }
}
//---------------------------task2-----------------------------


int fixstr(char *str) {

    if (*str == '\0')
        return 0;

    if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z'))
        putchar(*str);

    return fixstr(str + 1);
}
//---------------------------task3-----------------------------

int CheckSmall(char *a) {

	if ((*a >= 'A' && *a <= 'Z') || (*a >= '0' && *a <= '9'))
		return 0;
    if (*a == '\0')
        return 1;
	CheckSmall(a + 1);

}

//----------------------task4----------------------

int CheckOneNum(char *str) {
    if (!(*str >= '0' && *str <= '9'))
        return 0;
    else if ((*str >= '0' && *str <= '9'))
        return 1;

    if (*str == '\0')
        return 1;
    return CheckOneNum(str + 1);
}

//----------------------task5----------------------


int FibonacciCheck(int* arr, int size5)
{
	if (size5 <= 2)
	
		return 1;
	
	if (!((*arr) + (*(arr + 1)) == (*(arr + 2))))
	
		return 0;
	
	FibonacciCheck(++arr, --size5);
}

//----------------------task6----------------------
int MinusPlus(int *arr, int size6) {
	if ( size6 == 1)
		return 1;
	
	/*if(arr[size6-2]<0 && arr[size6 - 1]<0 || (arr[size6 - 2]>0 && arr[size6 - 1]>0))
		return 0;*/
	if (arr[size6 - 1] < 0)
		if (arr[size6 - 2] < 0)
			return 0;
	if (arr[size6 - 1] > 0)
		if (arr[size6 - 2] > 0)
			return 0;
	
	
	MinusPlus(arr, size6 - 1);

}

////----------------------task7----------------------
long CountOddRecursive(long number)

{

	if (number == 0)

		return 0;


	// value will 0 when even

	// value will be 1 when odd

	long value = (number % 10) % 2;

	return value + CountOddRecursive(number / 10);

}
