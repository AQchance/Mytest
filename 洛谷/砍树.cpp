#include <bits/stdc++.h>

using namespace std;
//一遍直接AC，超级爽，很有成就感哈哈哈哈哈哈哈
//最终的时间复杂度应该是O(nlogm)，还不错了
int HighestLocation(int a[], int m,int n) {
	long sumh = 0;
	int highest = 0, i, j, lowest = 0, mid;
	for (i = 0; i < n; i++) {
		highest = max(highest, a[i]);
	}
	while (lowest <= highest) {
		sumh = 0;
		mid = (lowest + highest) / 2;
		for (i = 0; i < n; i++) {
			if (a[i] > mid) sumh += (a[i] - mid);
		}
		if (lowest == highest) {
			if (sumh < m) return lowest-1;
			else return mid;
		}
		if (sumh < m) highest = mid - 1;
		else if (sumh == m) return mid;
		else if (sumh > m) lowest = mid + 1;
	}
}

int main()
{
	int m, n, i;
	cin >> n >> m;
	int* a = new int[n];
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << HighestLocation(a, m, n);
	delete[] a;
	return 0;
}