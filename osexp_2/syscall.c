#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    /**
     * total: 10000 * 10000 times
     * + - * / each 2500000 times
     */

	/*clock_t clockstart, clockend;
	double duration;

	clockstart = clock();*/

    const int count = 25000000;
    int i;
    for(i=0;i<count;i++) // +
    {
        int result;
        char op_add = '+';
        long ret=syscall(666,&result,10,10,&op_add);
    }
    for(i=0;i<count;i++) // -
    {
        int result;
        char op_sub = '-';
        long ret=syscall(666,&result,20,10,&op_sub);
    }
    for(i=0;i<count;i++) // *
    {
        int result;
        char op_mul = '*';
        long ret=syscall(666,&result,10,10,&op_mul);
    }
    for(i=0;i<count;i++) // '//'
    {
        int result;
        char op_div = '/';
        long ret=syscall(666,&result,20,10,&op_div);
    }

	/*clockend = clock();
	duration = (double)(clockend - clockstart) / CLOCKS_PER_SEC;
	printf( "%f seconds\n", duration );*/
	//gettimeofday(&end, NULL);
    //timeuse = 1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec - start.tv_usec;
    //printf("calc  clock time=%.3fs, timeofday=%.3fs\n", (double)(clockend-clockstart)/CLOCKS_PER_SEC, (double)timeuse/1000000);

    return 0;
}