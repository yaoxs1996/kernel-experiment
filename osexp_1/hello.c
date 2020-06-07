#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/moduleparam.h>
#include <linux/list.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

static char* whom = "world";
static int num = 1;

//传递命令参数 S_IRUGO 指明参数可以被所有人读取 
module_param(whom, charp, S_IRUGO);
module_param(num, int, S_IRUGO);

struct linkedlist
{
    int val;
    struct list_head list;
};

//程序中必须有下列两个函数
static int hello_init(void)
{
    struct list_head num_head;       // 头结点
    struct linkedlist *temp;     // 临时结点
    INIT_LIST_HEAD(&num_head);       // 初始化头结点

    int i;
    int sum = 0;
    for (i=0;i<num;i++){
    //使用的是printk 不是printf（其是C库函数）
    printk(KERN_ALERT "hello,%s\n",whom);

    temp = (struct linkedlist*)kmalloc(sizeof(struct linkedlist), GFP_KERNEL);    // 通常使用GFP_KERNEL，驱动程序使用GFP_ATOMIC
    temp->val = i + 1;
    list_add(&(temp->list), &(num_head));       // 头插法加入结点
    }

    struct list_head *pos;
    list_for_each(pos, &num_head)
    {
        /* params: ptr, type, member */
        temp = list_entry(pos, struct linkedlist, list);
        printk(KERN_ALERT "value is %d\n", temp->val);
        sum += temp->val;
    }

    /* 变通的浮点除法 */
    int integer = sum / num;        // 获得平均值的整数部分
    int precision = 1000;       // 小数精度
    int decimal = (sum % num) * precision / num;        // 小数部分

    printk(KERN_ALERT "mean is %d.%d\n", integer, decimal);
    return 0;
}

static void hello_exit(void)
{
    printk(KERN_ALERT "goodbye,kernel/n");
}

//加载or卸载模块
module_init(hello_init);
module_exit(hello_exit);

// 可选 
MODULE_AUTHOR("yaoxiaoshun");
MODULE_DESCRIPTION("1st experience!/n");
MODULE_VERSION("v1.0");
MODULE_ALIAS("Linked List");