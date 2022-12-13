#include <bits/stdc++.h>

using namespace std;

typedef struct JustSoSo {
	int value = 0;
	bool is_set = 0;
}HashInfo;

int Elem_Is_Set(HashInfo H[], int m, int x, int n) {
	int i, j;
	i = x % n;
	if (H[i].is_set == 0) {
		return -1000;
	}
	else if (H[i].value == x) return i + 1;
	else {
		for (j = 0; j < m; j++) {
			if (i == m - 1) i = 0;
			else i++;
			if (H[i].is_set == 0) return -i;
			else if (H[i].value == x) return i + 1;
		}
	}
}

int main()
{
	int i, j, k, m, n, l, cnt = 0;
	HashInfo H[100];
	int a[100] = { 0 };
	cin >> m >> n;
	i = 0;
	while (1) {
		cin >> k;
		if (k == -1) break;
		l = Elem_Is_Set(H, m, k, n);
		if (l > 0) {
			a[cnt] = l - 1;
			i++;
		}
		else if (i != m - 1) {
			if (l == -1000) {
				j = k % n;
				a[cnt] = j;
				H[j].is_set = 1;
				H[j].value = k;
			}
			else {
				j = -l;
				a[cnt] = j;
				H[j].is_set = 1;
				H[j].value = k;
			}
			i++;
		}
		else {
			a[cnt] = -1;
			cnt++;
			break;
		}
		cnt++;
	}
	for (i = 0; i < cnt; i++) {
		if (a[i] == -1) cout << "Table full" << endl;
		else cout << a[i] << endl;
	}
	return 0;
}