#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define N 80

int RorateString(char s[], int num, int side);
void Expression();
int main() {

    char s[N];
    int side, number;
    printf("Task5\n");

    printf("Enter a string:---> ");
    fgets(s, N, stdin);
    printf("Enter number of character to shift: ---> ");
    scanf("%d", &number);
    printf("Enter side (1 <--- left // 2 ---> right):---> ");
    scanf("%d", &side);

    //call function
    RorateString(s, number, side);
    printf("\n");
    printf("Task6\n");
    Expression();
    return 0;

}


int RorateString(char s[], int num, int side) {
    int l, i, ch, num1;

    for (l = 0;s[l];l++);
    //left side
    num1 = num;
    if (side == 1) {
        while (num > 0) {
            ch = s[l - 2];
            for (i = l - 1;i > 0;i--) {
                s[i - 1] = s[i - 2];
            }
            s[0] = ch;
            num--;
        }//while
    }//if
    //right side
    if (side == 2) {
        while (num > 0) {
            ch = s[0];
            for (i = 0;i < l - 1;i++) {
                s[i] = s[i + 1];
            }
            s[l - 2] = ch;
            num--;
        }
    }

    printf("Your string after shift: ---> ");
    puts(s);

    return 0;
}

void Expression() {

    char equation[N];
    int i = 0, j = 0, count = 0, count2 = 0, count3 = 0, arthm_operator1, index1, index2, index3;
    int num1 = 0, num2 = 0, num3 = 0, increment, arthm_operator2;
    int first_num[N], second_num[N], third_num[N];
    double x1, x2, resroot, root;
    printf("Enter expression \n");


    fgets(equation, N, stdin);
    fgets(equation, N, stdin);

    // First number
    if (equation[0] == '-')
        i++;

    for (i = i; (equation[i]) != '\0'; i++) {

        if ((int)equation[i] >= 48 && (int)equation[i] <= 57) {//0 --- 9

            first_num[j] = (int)equation[i] - 48;
            count++;
            j++;
        }

        else {
            index1 = i;
            //printf("index1 = %d\n", index1);//test
            arthm_operator1 = equation[index1 + 3];//234x^2 + 434x ---> +
            if (arthm_operator1 != '+')
                arthm_operator1 = '-';

            //	printf("arthm_operator1 = %d\n", arthm_operator1);//test
            break;
        }
    }


    for (i = 0; i < count; i++) {

        if (i == 0)
            increment = 1;
        else
            increment = increment * 10;

        num1 = first_num[count - i - 1] * increment + num1;
    }

    //printf("num1 = %d\n", num1);//test

    if (equation[0] == '-') {
        num1 = -num1;
        //	printf("num1 = %d\n", num1);//test
    }
    if (equation[0] == 'x' || equation[0] == 'X')
        num1 = 1;
    //printf("num1 = %d\n", num1);//test

    //--------------- Second number
    j = 0;
    if (equation[0] == '-')
        count += 5;
    else
        count += 4;

    count = count;
    for (i = count; (equation[i]) != '\0'; i++) {

        if ((int)equation[i] >= 48 && (int)equation[i] <= 57) {
            first_num[i] = (int)equation[i] - 48;
            second_num[j] = first_num[i];
            count2++;
            j++;

        }

        else {
            index2 = i;
            //	printf("index2 = %d\n", index2);//test
            arthm_operator2 = equation[index2 + 1];//234x + 434 ---> +
            if (arthm_operator2 != '+')
                arthm_operator2 = '-';
            //	printf("arthm_operator2 = %d\n", arthm_operator2);//test
            break;
        }
    }


    increment = 0;
    for (i = 0; i < count2; i++) {

        if (i == 0)
            increment = 1;
        else
            increment = increment * 10;

        num2 = second_num[count2 - i - 1] * increment + num2;
    }

    //	printf("num2 = %d\n", num2);//test
    if (arthm_operator1 == '-') {
        num2 = -num2;
        //	printf("num2 = %d\n", num2);//test
    }

    if (equation[count] == 'x' || equation[count] == 'X') {
        num2 = 1;
        //printf("num2 = %d\n", num2);//test
    }

    if (equation[count2] == '=') {
        num2 = 0;
        //printf("num2 = %d\n", num2);//test
    }
    //---------------Third number
    j = 0;

    for (i = index2 + 2; (equation[i]) != '\0'; i++) {

        if ((int)equation[i] >= 48 && (int)equation[i] <= 57) {
            first_num[i] = (int)equation[i] - 48;
            third_num[j] = first_num[i];
            count3++;
            j++;

        }

        else {
            index3 = i;
            //	printf("index3 = %d\n", index3);//test
            break;
        }
    }


    increment = 0;

    for (i = 0; i < count3; i++) {

        if (i == 0)
            increment = 1;
        else
            increment = increment * 10;

        num3 = third_num[count3 - i - 1] * increment + num3;
    }

    //printf("num3 = %d\n", num3);//test

    if (arthm_operator2 != '+') {
        num3 = -num3;
    }


    //descremenant
    root = num2*num2 - 4 * num1*num3;
    resroot = sqrt(root);
    x1 = (-num2 + resroot) / (2 * num1);
    x2 = (-num2 - resroot) / (2 * num1);
    if ( x2 == -0.000000 || x1 == -0.000000) {
        x1 = x1*(-1);
    }
    printf("X1 = %lf,\t X2 = %lf\n", x1, x2);



}
