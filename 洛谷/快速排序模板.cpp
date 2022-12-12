#include<iostream>
#include<algorithm>
#include<malloc.h>
using namespace std;

void quicksort(int a[],int l, int r)//应用二分思想
{
    int mid = a[(l + r) / 2];//中间数
    int i = l, j = r;
    do {
        while (a[i] < mid) i++;//查找左半部分比中间数大的数
        while (a[j] > mid) j--;//查找右半部分比中间数小的数
        if (i <= j)//如果有一组不满足排序条件（左小右大）的数
        {
            swap(a[i], a[j]);//交换
            i++;
            j--;
        }
    } while (i <= j);
    if (k<=j) quicksort(a, l, j);//递归搜索左半部分
    if (k>=i) quicksort(a, i, r);//递归搜索右半部分
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