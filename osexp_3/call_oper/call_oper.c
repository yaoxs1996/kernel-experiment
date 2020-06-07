#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/moduleparam.h>
#include <linux/timer.h>
#include <linux/ktime.h>

static int func(void)
{
    extern long oper_yao(int *result, int num1, int num2, char *op);
    printk(KERN_ALERT "已调用\n");

    ktime_t start, end;
    s64 actual_time;

    start = ktime_get();

    const int count = 25000000;
    int i;
    long temp = 0;
    for(i=0;i<count;i++) // +
    {
        int result;
        char op_add = '+';
        long ret = oper_yao(&result,10,10,&op_add);
        temp++;
    }
    for(i=0;i<count;i++) // -
    {
        int result;
        char op_sub = '-';
        long ret = oper_yao(&result,20,10,&op_sub);
        temp++;
    }
    for(i=0;i<count;i++) // *
    {
        int result;
        char op_mul = '*';
        long ret = oper_yao(&result,10,10,&op_mul);
        temp++;
    }
    for(i=0;i<count;i++) // '//'
    {
        int result;
        char op_div = '/';
        long ret = oper_yao(&result,20,10,&op_div);
        temp++;
    }

    end = ktime_get();
    actual_time = ktime_to_ms(ktime_sub(end, start));

    printk(KERN_ALERT "执行 %ld 次操作，耗时 %u ms\n", temp, (unsigned int)actual_time);
}

static int __init call_oper_init(void)
{
    printk(KERN_ALERT "开始调用\n");
    func();
    return 0;
}

static void __exit call_oper_exit(void)
{
    printk(KERN_ALERT "完成调用\n");
}

MODULE_LICENSE("GPL");
MODULE_VERSION("1.0");

//加载or卸载模块
module_init(call_oper_init);
module_exit(call_oper_exit);