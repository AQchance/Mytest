#include <stdio.h>
#include <time.h>
//�����������������ȫ��Ϊ����ʱ�䣬
//���Ҫ�������ͳһ��׼������������̨��׼ʱ�䣬����Ҫ����ʱ�����߲�������������ʵ��
int main()
{
	time_t biggest = 0x7FFFFFFF;//time.h�б�ʾ��������ڡ�
	time_t now = time(NULL);//����ΪNUll��ʾ��ȡ���ڵ����ڣ�
	printf("biggest = %s \n", ctime(&biggest));
	printf("now = %s \n", ctime(&now));
	int t = difftime(biggest, now);//difftime�����������ڵĲ�ֵ�������������ʾ
	printf("%d\n", t);
	t = t / (60 * 60 * 24 * 365);//���������ڵĲ�ֵ����Ϊ��λ��ʾ����������Ȼ��С��һ���˵�������
	printf("%d", t);
	return 0;
}