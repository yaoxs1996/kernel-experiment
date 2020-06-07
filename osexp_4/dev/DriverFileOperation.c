#include "DriverFileOperation.h"

int DriverOpen(struct inode *pInodeStruct, struct file *pFileStruct)
{
    DeviceOpenNumbers++;
    printk(DEVICE_NAME ": device opened %d times.\n",DeviceOpenNumbers);
    return 0;
}

int DriverRelease(struct inode *pInodeStruct, struct file *pFileStruct)
{
    printk(DEVICE_NAME ": close invoked.\n");
    return 0;
}

ssize_t DriverRead(struct file *pFileStruct, char __user *pBuffer, size_t count, loff_t *pOffset)
{
    int error_count = 0;
    /* 重写 */
    error_count = copy_to_user(pBuffer,&msg[*pOffset],size_of_msg);
    if(error_count == 0)
    {
        printk(DEVICE_NAME ":send %d characters to user.\n", size_of_msg);
        return (size_of_msg=0);
    }
    else
    {
        printk(DEVICE_NAME ":failed to read from device.\n");
        return -EFAULT;
    }
    //printk(DEVICE_NAME ":read invoked.\n");
    //return 0;
}

ssize_t DriverWrite(struct file *pFileStruct, const char __user *pBuffer, size_t count, loff_t *pOffset)
{
    sprintf(msg, "%s(%d letters)", pBuffer, count);
    size_of_msg = strlen(msg);
    printk(DEVICE_NAME ": received %d characters from the user.\n",count);
    return 0;
}

loff_t DriverLseek(struct file *pFileStruct, loff_t pOffset, int orig)
{
    loff_t pos;
    pos = pFileStruct->f_pos;

    switch (orig)
    {
    /* SEEK_SET */
    case 0:
        pos = pOffset;
        break;
    /* SEEK_CUR */
    case 1:
        pos += pOffset;
        break;
    /* SEEK_END */
    case 2:
        pos = 1024 + pOffset;
        break;
    default:
        return -EINVAL;     // 无效参数
    }

    if((pos > 1024) || (pos < 0))
    {
        printk(DEVICE_NAME ": lseek error %d\n", pos);
        return -EINVAL;
    }

    return pFileStruct->f_pos = pos;
}