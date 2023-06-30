#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
int CreateDataBase(char *dbname)
{

    if (mkdir(dbname, S_IRWXU) == 0)
    {
        printf("数据库创建成功！\n");

        char filename[100]={'\0'};
        strcat(filename, dbname);
        strcat(filename, "/");
        strcat(filename, dbname);
        strcat(filename, ".txt");
        FILE* file = fopen(filename, "w");
        if (file != NULL) {

            printf("数据库文件创建成功！\n");
            // 关闭文件
            fclose(file);
        }
        else{
            printf("数据库文件创建失败！\n");
        }
        return 1;
    }
    else{
        printf("数据库创建失败！数据库可能已经存在！\n");
        return 0;
    }
}
