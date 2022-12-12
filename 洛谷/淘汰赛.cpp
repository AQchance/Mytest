#include <bits/stdc++.h>
//此题使用队列会节省更多的存储空间（直接减少一个指数数量级）
using namespace std;

int Index2(int n) {
	int y = 1;
	for (int i = 0; i < n; i++) {
		y *= 2;
	}
	return y;
}

typedef struct Information {
	int number;
	int value;
}Info;

int Result(Info a[], int n) {
	if (n == 2) {
		if (a[0].value < a[1].value) return a[0].number;
		else return a[1].number;
	}
	else {
		Info* b = new Info[n / 2];
		for (int i = 0; i < n; i += 2) {
			if (a[i].value > a[i + 1].value) {
				b[i / 2] = a[i];
			}
			else b[i / 2] = a[i + 1];
		}
		Result(b, n / 2);
	}
}

int main()
{
	int n, i, j;
	cin >> n;
	j = Index2(n);
	Info* a = new Info[j];
	for (int i = 0; i < j; i++) {
		cin >> a[i].value;
		a[i].number = i+1;
	}
	cout << Result(a, j);
	return 0;
}