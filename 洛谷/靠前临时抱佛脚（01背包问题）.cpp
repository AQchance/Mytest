#include <bits/stdc++.h>

using namespace std;

int dp[21][601] = { 0 };

int main()
{	
	ios::sync_with_stdio(false);
	int sum = 0, i, j, k, m;
	int a[5] = { 0 };
	int t[21] = { 0 };
	for (k = 1; k <= 4; k++) {
		cin >> a[k];
	}
	for (k = 1; k <= 4; k++) {
		m = 0;
		for (i = 1; i <= a[k]; i++) {
			cin >> t[i];
			m += t[i];
		}
		sort(t, t + a[k]);
		int t1 = 0;
		for (i = 1; i <= a[k]; i++) {
			for (j = 0; j <= m / 2; j++) {
				if (j < t[i]) dp[i][j] = dp[i - 1][j];
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i]] + t[i]);
				}
				t1 = max(t1, dp[i][j]);
				/*dp[i][j] = dp[i - 1][j];
				if (j >= t[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i]] + t[i]);*/	
			}
		}
		sum += max(t1, m - t1);
	}
	cout << sum;
}