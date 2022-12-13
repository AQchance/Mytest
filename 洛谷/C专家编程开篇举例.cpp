#include <stdio.h>
#include <time.h>
//本程序中输出的日期全部为北京时间，
//如果要获得世界统一标准格林尼治天文台标准时间，还需要进行时差换算或者采用其他函数来实现
int main()
{
	time_t biggest = 0x7FFFFFFF;//time.h中表示的最大日期。
	time_t now = time(NULL);//参数为NUll表示获取现在的日期，
	printf("biggest = %s \n", ctime(&biggest));
	printf("now = %s \n", ctime(&now));
	int t = difftime(biggest, now);//difftime计算两个日期的差值，结果用秒来表示
	printf("%d\n", t);
	t = t / (60 * 60 * 24 * 365);//将两个日期的差值用年为单位表示出来，很显然是小于一般人的寿命的
	printf("%d", t);
	return 0;
}