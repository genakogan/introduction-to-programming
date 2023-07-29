//
// Created by rgkogan on 7/21/2023.
//
#include <stdio.h>
#include <stdlib.h> // for free function

int  division(int);
void forNestedLoop();
void whileNestedLoop();
void arrayExample();
void pointers();
void swap(int *, int *);
void memoryAllocation();

int main()
{
    int number;
    printf("Start examples\n");
    //printf("Enter number for division function: ");
    //scanf(" %d",&number);
    //division(number);
    //printf("division function return number: %d", division(number));
    //forNestedLoop(); //for example
    //whileNestedLoop(); //while example
    arrayExample();
    //pointers();
    //memoryAllocation();
   return 0;
}
//======================================================================
int  division(int number){

    int quotient, remainder,divisor = 10 ;
    //printf("Enter divisor: ");
    //scanf("%d", &divisor);
    // Computes quotient
    quotient = number / divisor;
    printf("Computes quotient: %d\n",quotient);
    // Computes remainder
    remainder = number % divisor;
    printf("Computes remainder: %d\n",remainder);

    return number;
}
//======================================================================
void forNestedLoop(){
    int n; // variable declaration
    printf("Enter the value of n :");
    scanf("%d",&n);

    for(int i=1;i<=n;i++)  // outer loop
    {
        for(int j=1;j<=10;j++)  // inner loop
        {
            printf("%d\t",(i*j)); // printing the value.
        }
        printf("\n");
    }
}
//======================================================================
void whileNestedLoop(){
    int rows;  // variable declaration
    int columns; // variable declaration
    int k=1; // variable initialization
    printf("Enter the number of rows :");  // input the number of rows.
    scanf("%d",&rows);
    printf("\nEnter the number of columns :"); // input the number of columns.
    scanf("%d",&columns);
    int i=1;
    while(i<=rows) // outer loop
    {
        int j=1;
        while(j<=columns)  // inner loop
        {
            printf("%d\t",k);  // printing the value of k.
            k++;   // increment counter
            j++;
        }
        i++;
        printf("\n");
    }
}
//======================================================================
void arrayExample(){
    int myNumbers[7] = {25, 50, 75, 100};
    int i=0, count=0;
    while(myNumbers[count]) {
       count++;
    }
    printf("count = %d\n", count);
    printf("Index 0: %d\n", myNumbers[0]);
    myNumbers[0] = 33;
    printf("Index 0: %d\n", myNumbers[0]);
    printf("Index 0: %d\n", myNumbers[3]);
    for (int i=0; i<4; i++) {
        printf("%d\n", myNumbers[i]);
    }
    for (int i=0; i<4; i++)
        myNumbers[i] = i;
    for (int i=0; i<4; i++) {
        printf("%d\n", myNumbers[i]);
    }
    // char section
    char greetings[] = "Hello World!";
    printf("%s\n", greetings);

    char carName[] = "Volvo";
    for (i = 0; i < 5; ++i) {
        printf("%c\n", carName[i]);
    }

    char greetings2[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'};
    printf("%s\n", greetings);
    printf("%lu\n", sizeof(greetings));   // Outputs 13
    printf("%lu\n", sizeof(greetings2));  // Outputs 13


}
//======================================================================
void  pointers(){
    int x = 10,num1,num2;     // defining a variable
    int *p;         // defining a pointer
    p = &x;         // the pointer receives the address of the variable
    printf("%p \n", p);     // for example 0060FEA8 - machine address of variable x
    printf("p: %d \n",  *p);
    int y = *p;     // assigning the variable y the value at the address pointed to by pointer p
    printf("y: %d \n",  y);
    *p = 45;
    printf("y = %d \n", x);
    printf("y = %d \n", y);

    num1 = x;
    num2 = y;

    // address of num1 and num2 is passed
    swap(&num1,&num2);
}

void swap(int * num1, int * num2){
    printf("num1 is: %d, num2 is %d\n", *num1, *num2);
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
    printf("num1 is: %d, num2 is %d", *num1, *num2);

}
//======================================================================
void memoryAllocation(){

    // This pointer will hold the
    // base address of the block created
    int* ptr;
    int n, i;

    // Get the number of elements for the array
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Entered number of elements: %d\n", n);

    // Dynamically allocate memory using malloc()
    ptr = (int*)malloc(n * sizeof(int));

    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {

        // Memory has been successfully allocated
        printf("Memory successfully allocated using malloc.\n");

        // Get the elements of the array
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }

        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
    }
    free(ptr);
}

