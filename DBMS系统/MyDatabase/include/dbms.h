#include <stdio.h>

int CreateDataBaseTxt()
{
    FILE *file = fopen("database.txt", "w"); // 打开文件以写入模式创建

    if (file == NULL)
    {
        printf("数据库文件创建失败！\n");
        return 0;
    }
    else{
        printf("数据库文件创建成功！\n");
        return 1;
    }
}