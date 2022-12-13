#include <bits/stdc++.h>

using namespace std;

int Index2(int x, int n) {
	for (int i = 1; i < n; i++) {
		x *= 2;
	}
	return x;
}

typedef struct NodeInfo {
	int a[1000] = { 0 };
	int depth;
	int cntNode;
}Node;

int main()
{
	int i, j, k, m, n = 0, l;
	Node N[40];
	while (1) {
		cin >> m;
		if (m == 0) break;
		else {
			N[n].cntNode = m;
			for (i = 1; i <= m; i++) {
				cin >> N[n].a[i];
			}
			cin >> N[n].depth;
			n++;
		}
	}
	for (i = 0; i < n; i++) {
		l = Index2(2, N[i].depth) - 1;
		j = Index2(2, N[i].depth - 1);
		if (j > N[i].cntNode) {
			cout << "EMPTY" << endl;
			continue;
		}
		else {
			for (; j <= l && j <= N[i].cntNode; j++) {
				if (j == l || j == N[i].cntNode)cout << N[i].a[j] << endl;
				else cout << N[i].a[j] << " ";
			}
		}
	}
	return 0;
}