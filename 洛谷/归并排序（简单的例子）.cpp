#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[200] = { 0 };
	int i, n, m;
	cin >> n >> m;
	for (i = 0; i < n + m; i++) {
		cin >> a[i];
	}
	sort(a, a + n + m);
	for (i = 0; i < n + m; i++) {
		cout << a[i] << " ";
	}
	return 0;
}