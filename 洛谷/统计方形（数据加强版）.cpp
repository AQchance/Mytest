#include <bits/stdc++.h>

using namespace std;
//�����ù�ʽû����ʱ��˼��һ���ǲ������ݷ�Χ�����˴���int��ʱ������
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