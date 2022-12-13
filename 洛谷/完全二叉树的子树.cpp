#include <bits/stdc++.h>

using namespace std;

void cntNode(int m, int n, int& cnt) {
	if (m * 2 < n) {
		cnt++;
		cntNode(m * 2, n, cnt);
	}
	else if (m * 2 == n) {
		cnt++;
		return;
	}
	else if (m * 2 > n) return;
	if (m * 2+1 < n) {
		cnt++;
		cntNode(m * 2+1, n, cnt);
	}
	else if (m * 2+1 == n) {
		cnt++;
		return;
	}
	else if (m * 2+1 > n) return;
}

int main()
{
	int i, k=0, m, n, cnt;
	int a[1000] = { 0 };
	while (1) {
		cnt = 1;
		cin >> m >> n;
		if (m == 0 && n == 0) break;
		else {
			cntNode(m, n, cnt);
			a[k] = cnt;
			k++;
		}
	}
	for (i = 0; i < k; i++) {
		cout << a[i] << endl;
	}
	return 0;
}