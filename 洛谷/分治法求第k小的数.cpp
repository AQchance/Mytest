#include<iostream>
#include<algorithm>
#include<malloc.h>
using namespace std;
int knumber(int a[], int l, int r, int k)//应用二分思想
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
    if (k == j + 1) return a[k];
    else if (k <= j) knumber(a, l, j, k);//递归搜索左半部分
    else if (k >= i) knumber(a, i, r, k);//递归搜索右半部分
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