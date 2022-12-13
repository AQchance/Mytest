#include <bits/stdc++.h>

using namespace std;
//递归超时了,而且Stack Overflow，所以试试循环
int findnumfirst(int a[], int l, int r, int n) {
	if (l > r) return -1;
	int mid = (l + r) / 2;
	if (a[mid] == n) {
		int i = mid - 1;
		while (i >= 0 && a[i] == a[mid]) {
			i--;
		}
		return i + 2;//加一因为上一个满足条件，但是最后循环还是减一了,
					//加两个一是因为编号不是从0开始而是从1开始
					//为什么止步于此呢，不要让二分停下来！
					//此函数作废，使用下面的新函数
	}
	else {
		if (n < a[mid]) return findnumfirst(a, l, mid - 1, n);
		else return findnumfirst(a, mid + 1, r, n);
	}
}

int findnum(int a[], int l, int r, int n) {
	while (l <= r) {
		int mid = (l + r) / 2;
		if (a[mid] == n) {
			int k = findnum(a, l, mid - 1, n);
			if (k != -1) {
				r = k;
				continue;
			}
			else {
				return mid + 1;
			}
		}
		else {
			if (n < a[mid]) r = mid - 1;
			else l = mid + 1;
		}
	}
	return -1;
}

int main()
{
	int n, m;
	int i;
	cin >> n >> m;
	int* a = new int[n];
	int* b = new int[m];
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (i = 0; i < m; i++) {
		cin >> b[i];
	}
	for (i = 0; i < m; i++) {
		cout << findnum(a, 0, n - 1, b[i]) << " ";
	}
	delete[] a;
	delete[] b;
	return 0;
}