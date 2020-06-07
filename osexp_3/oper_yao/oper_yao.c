#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/moduleparam.h>

/*static int num1 = 0;
static int num2 = 0;
static char* op = "+";*/

//传递命令参数 S_IRUGO 指明参数可以被所有人读取 
/*module_param(num1, int, S_IRUGO);
module_param(num2, int, S_IRUGO);
module_param(op, charp, S_IRUGO);*/

long oper_yao(int *result, int num1, int num2, char *op)
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
            *result = num1 * num2;
        }
        else if(*op == '/')
        {
            if(num2 != 0)
                *result = num1 / num2;
            else
                printk(KERN_ALERT "dived number can't be zero!\n");
        }else
            printk(KERN_ALERT "unrecongized operator %c\n", *op);
    }else
    {
        printk(KERN_ALERT "operation is empty.\n");
    }
    return 0;
}

// 程序中必须有下列两个函数
static int __init oper_init(void)
{
    printk(KERN_ALERT "加载四则运算模块\n");
    return 0;
}

static void __exit oper_exit(void)
{
   printk(KERN_ALERT "卸载四则运算模块\n");
}

EXPORT_SYMBOL(oper_yao);

//加载or卸载模块
module_init(oper_init);
module_exit(oper_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("1.0");