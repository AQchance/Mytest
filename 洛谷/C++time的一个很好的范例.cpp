#include <ctime>
#include <iostream>

using namespace std;

int main()
{
	cout << "Enter the delay time,in seconds:";
	float secs;
	cin >> secs;
	clock_t delay = secs * CLOCKS_PER_SEC;//头文件定义的一个数，表示一秒钟有多少个系统时间单位数
	clock_t start = clock();
	while (clock() - start < delay);//循环中为空，表示等待
	cout << "done \a\n";//转义字符/a表示响铃
	return 0;
}