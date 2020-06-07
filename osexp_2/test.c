#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int result = 0;
    char op_add = 'k';
    long ret = syscall(666, &result, 10, 10, &op_add);
    printf("result = %d, ret = %ld", result, ret);
    return 0;
}