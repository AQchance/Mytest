#include <bits/stdc++.h>

using namespace std;

int a[25] = { 0 };

void Cnr(int n, int r,int num) {
	if (num > r) {
		for (int i = 1; i <= r; i++) {
			cout << setw(3) << a[i];
		}
		cout << endl;
		return;
	}
	for (int i = a[num - 1] + 1; i <= n; i++) {//�˴���ʼ��i���һ��1����Ϊ�������һ�������ٱȵ�ǰ����1����λ
		a[num] = i;
		Cnr(n, r, num + 1);
	}
}

int main()
{
	int n, r;
	cin >> n >> r;
	Cnr(n, r,1);
	return 0;
}