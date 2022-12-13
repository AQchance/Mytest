#include <bits/stdc++.h>

using namespace std;

int CountBubbleSort(int a[], int low, int high) {
	int cnt = 0, exit, i;
	while (1) {
		exit = 1;
		for (i = low; i < high; i++) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				exit = 0;
				cnt++;
			}
		}
		if (exit == 1) return cnt;
	}
}

int main()
{
	int i, n;
	int a[100] = { 0 };
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	i = CountBubbleSort(a, 0, n - 1);
	cout << i;
	return 0;
}