#include<iostream>
#include<algorithm>
#include<malloc.h>
using namespace std;

void quicksort(int a[],int l, int r)//Ӧ�ö���˼��
{
    int mid = a[(l + r) / 2];//�м���
    int i = l, j = r;
    do {
        while (a[i] < mid) i++;//������벿�ֱ��м��������
        while (a[j] > mid) j--;//�����Ұ벿�ֱ��м���С����
        if (i <= j)//�����һ�鲻����������������С�Ҵ󣩵���
        {
            swap(a[i], a[j]);//����
            i++;
            j--;
        }
    } while (i <= j);
    if (k<=j) quicksort(a, l, j);//�ݹ�������벿��
    if (k>=i) quicksort(a, i, r);//�ݹ������Ұ벿��
}
int main()
{
	int n;
	scanf("%d", &n);
	int a[100001] = { 0 };
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	quicksort(a, 0, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}