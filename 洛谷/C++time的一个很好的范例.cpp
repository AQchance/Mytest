#include <ctime>
#include <iostream>

using namespace std;

int main()
{
	cout << "Enter the delay time,in seconds:";
	float secs;
	cin >> secs;
	clock_t delay = secs * CLOCKS_PER_SEC;//ͷ�ļ������һ��������ʾһ�����ж��ٸ�ϵͳʱ�䵥λ��
	clock_t start = clock();
	while (clock() - start < delay);//ѭ����Ϊ�գ���ʾ�ȴ�
	cout << "done \a\n";//ת���ַ�/a��ʾ����
	return 0;
}