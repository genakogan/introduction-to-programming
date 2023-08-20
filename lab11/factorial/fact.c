#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>


#include<stdio.h>

#include<conio.h>

int fact(int a); /* Definition of Function */

void main()

{

int number, result;

	clrscr();

	printf(“Please enter a non-negative number here: “);

	scanf(“%d”,&number);

	result = factorial(number); /* Function Calling in a Normal way */

	printf(“%d! = %d” ,number ,result);

	getch();

}

int factorial(int a) /* Definition of Function */

{

	int x=1;

	if(a <= 0)

		{

		return(1);

		}

	else

		{

		x = a * factorial(a-1); /* Function Call Recursively as the fact() calls itself in the program */

		return(x);

		}

}

