#include <bits/stdc++.h>

using namespace std;

bool isprime(int n) {
	if (n == 1) return false;
	if (n == 2 || n == 3) return true;
	else {
		for (int i = 2; i <= sqrt(n); i++) {
			if (n % i == 0) return false;
		}
		return true;
	}
}

int cnt = 0;
int k, n;
void dfs(int a[], int m, int sum, int st) {
	if (m == k) {
		if (isprime(sum)) cnt++;
		return;
	}
	for (int i = st; i < n; i++) {
		dfs(a, m + 1, sum + a[i], i + 1);//ÉýÐò²éÕÒ£¬·ÀÖ¹ÖØ¸´
	}
	return;
}

int main()
{
	int i, j, sum = 0;
	cin >> n >> k;
	int a[30] = { 0 };
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	dfs(a, 0, 0, 0);
	cout << cnt;
	return 0;
}