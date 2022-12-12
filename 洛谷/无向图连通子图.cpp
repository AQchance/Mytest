#include <bits/stdc++.h>

using namespace std;

typedef struct GraghInfo {
	int start;
	int end;
}Gragh;

int countnum(int a[], int n, int x) {
	int i;
	int sum = 0;
	for (i = 1; i <= n; i++) {
		if (a[i] == x) sum++;
	}
	return sum;
}

int main()
{
	int n, m, i, j, k;
	Gragh gragh[100];
	int sets[31] = { 0 };
	int cntarr[31] = { 0 };
	set<int> s;
	cin >> n >> m;
	for (i = 0; i < m; i++) {
		cin >> gragh[i].start >> gragh[i].end;
	}
	for (i = 1; i <= n; i++) {
		sets[i] = i;
	}
	for (i = 0; i < m; i++) {
		if (sets[gragh[i].start] == sets[gragh[i].end]) continue;
		else {
			if (sets[gragh[i].start] < sets[gragh[i].end]) {
				j = sets[gragh[i].end];
				for (k = 1; k <= n; k++) {
					if (sets[k] == j) sets[k] = sets[gragh[i].start];
				}
			}
			else {
				j = sets[gragh[i].start];
				for (k = 1; k <= n; k++) {
					if (sets[k] == j) sets[k] = sets[gragh[i].end];
				}
			}
		}
	}
	for (i = 1; i <= n; i++) {
		s.insert(sets[i]);
	}
	int cnt = 0;
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		k=countnum(sets, n, *it);
		cntarr[cnt] = k;
		cnt++;
	}
	sort(cntarr, cntarr + cnt);
	cout << cnt << endl;
	for (i = 0; i < cnt; i++) {
		cout << cntarr[i] << " ";
	}
	return 0;
}