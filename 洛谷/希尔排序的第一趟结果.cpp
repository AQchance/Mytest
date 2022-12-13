#include<bits/stdc++.h>

using namespace std;

void ShellFS(int a[], int n) {
	int l = n / 2;
	for (int i = 0; i < l; i++) {
		if (a[i] > a[i + l]) swap(a[i], a[i + l]);
	}
}

int main()
{
	int n, i, a[100] = { 0 };
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	ShellFS(a, n);
	for (i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}