#include <bits/stdc++.h>

using namespace std;
//当觉得公式没错误时，思考一下是不是数据范围出现了错误，int有时候不适用
int main()
{
	int i, n, m, j, k=1, l=1;
	long sum1 = 0, sum2 = 0;
	cin >> n >> m;
	while (k <= n && l <= m) {
		if (k == l) {
			sum1 += (n + 1 - k) * (m + 1 - l);
		}
		else sum2 += (n + 1 - k) * (m + 1 - l);
		if (k < n) {
			k++;
		}
		else {
			k = 1;
			l++;
		}
	}
	cout << sum1 << " " << sum2;
	return 0;
}