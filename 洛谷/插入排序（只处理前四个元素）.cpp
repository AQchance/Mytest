#include<bits/stdc++.h>

using namespace std;

void InsertTS(int a[],int n) {
	int i, j;
	if (a[0] > a[1]) swap(a[0], a[1]);
	for (i = 0; i < n; i++) {
		if (i == n - 1) cout << a[i] << endl;
		else cout << a[i] << " ";
	}
	if (a[2] < a[0]) {
		swap(a[2], a[0]);
		swap(a[1], a[2]);
	}
	else if (a[2] > a[0] && a[2] < a[1]) swap(a[1], a[2]);
	for (i = 0; i < n; i++) {
		if (i == n - 1) cout << a[i] << endl;
		else cout << a[i] << " ";
	}
	if (a[3] < a[0]) {
		swap(a[0], a[3]);
		swap(a[1], a[3]);
		swap(a[2], a[3]);
	}
	else if (a[3] > a[0] && a[3] < a[1]) {
		swap(a[3], a[1]);
		swap(a[3], a[2]);
	}
	else if (a[3] > a[1] && a[3] < a[2]) swap(a[2], a[3]);
	for (i = 0; i < n; i++) {
		if (i == n - 1) cout << a[i] << endl;
		else cout << a[i] << " ";
	}
}

int main()
{
	int n, a[100] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	InsertTS(a,n);
	return 0;
}