#include<iostream>
#include<algorithm>
#include<malloc.h>
using namespace std;
int knumber(int a[], int l, int r, int k)//Ӧ�ö���˼��
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
    if (k == j + 1) return a[k];
    else if (k <= j) knumber(a, l, j, k);//�ݹ�������벿��
    else if (k >= i) knumber(a, i, r, k);//�ݹ������Ұ벿��
}
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int* a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int m=knumber(a, 0, n - 1, k);
    printf("%d", m);
    free(a);
    return 0;
}