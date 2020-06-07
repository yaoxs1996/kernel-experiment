#include <stdio.h>
#include <time.h>

long operation(int* result,int num1,int num2,char* op)
{
    if(op)
    {
        if(*op == '+')
        {
            *result = num1 + num2;
        }
        else if(*op == '-')
        {
            *result = num1 - num2;
        }
        else if(*op == '*')
        {
            *result = num1*num2;
        }
        else if(*op == '\\')
        {
            if(num2!=0)
                *result = num1/num2;
            else
                printf("dived number can't be zero!\n");
        }else
            printf("unrecongized operator %c\n", *op);
    }else
    {
        printf("operation is empty.\n");
    }
    return 0;
}
int main()
{
    /**
     * total:10000*10000 times
     * + - * / each 2500000 times
     */
    int i;
    const int count = 25000000;

    /*clock_t clockstart, clockend;
	double duration;

    clockstart = clock();*/
    for(i=0;i<count;i++) // +
    {
        int result;
        char op_add = '+';
        operation(&result, 10, 10, &op_add);
    }
    for(i=0;i<count;i++) // -
    {
        int result;
        char op_sub = '-';
        operation(&result, 20, 10, &op_sub);
    }
    for(i=0;i<count;i++) // *
    {
        int result;
        char op_mul = '*';
        operation(&result, 10, 10, &op_mul);
    }
    /*for(i=0;i<count;i++) // '//'
    {
        int result;
        char op_div = '+';
        operation(&result, 20, 10, &op_div);
    }*/
    /*clockend = clock();
	duration = (double)(clockend - clockstart) / CLOCKS_PER_SEC;
	printf( "%f seconds\n", duration );*/
    return 0;
}
