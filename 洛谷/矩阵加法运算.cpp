#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a[100][100] = { 0 }, b[100][100] = { 0 };
	int nua[100] = { 0 }, nub[100] = { 0 }, nuc[100] = { 0 };
	int i, j, m, n, k = 0, p = 0, q = 0;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) p++;
		}
	}
	for (i = 0; i < p; i++) {
		cin >> nua[i];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> b[i][j];
			if (b[i][j] == 1) q++;
		}
	}
	for (i = 0; i < q; i++) {
		cin >> nub[i];
	}
	for (i = 0, p = 0, q = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (a[i][j] == 0 && b[i][j] == 0) {
				continue;
			}
			else if (a[i][j] != 0 && b[i][j] != 0) {
				if (nua[p] + nub[q] == 0) {
					a[i][j] = 0;
					p++; q++;
					continue;
				}
				else {
					nuc[k] = nua[p] + nub[q];
					k++; q++; p++;
				}
			}
			else if (a[i][j] != 0 && b[i][j] == 0) {
				nuc[k] = nua[p];
				k++;
				p++;
			}
			else if (a[i][j] == 0 && b[i][j] != 0) {
				nuc[k] = nub[q];
				k++; q++;
				a[i][j] = 1;
			}
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (j < m - 1) {
				cout << a[i][j] << " ";
			}
			else cout << a[i][j] << endl;
		}
	}
	for (i = 0; nuc[i] != 0; i++) {
		cout << nuc[i] << " ";
	}
	return 0;
}