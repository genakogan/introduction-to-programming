#include <stdio.h>
#include <stdlib.h>



void swap(int * num1, int * num2){
    printf("num1 is: %d, num2 is %d\n", *num1, *num2);
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
    printf("num1 is: %d, num2 is %d", *num1, *num2);

}
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

int main()
{
    pointers();
    return 0;
}