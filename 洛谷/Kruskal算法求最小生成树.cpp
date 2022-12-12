#include<bits/stdc++.h>

using namespace std;

typedef struct PathInfo {
	int start;
	int end;
	int value;
}Path;

bool cmp(Path a, Path b) {
	return a.value < b.value;
}

int main()
{
	int i, j, k = 0, l = 0, n, m, sets[31] = { 0 };
	Path path[100];
	cin >> n >> m;
	for (i = 0; i < m; i++) {
		cin >> path[i].start >> path[i].end >> path[i].value;
		if (path[i].start > path[i].end) swap(path[i].start, path[i].end);
	}
	for (i = 1; i <= n; i++) {
		sets[i] = i;
	}
	sort(path, path + m, cmp);
	for (i = 0; i < m && k < n - 1; i++) {
		if (sets[path[i].start] == sets[path[i].end]) continue;
		else {
			if (sets[path[i].start] < sets[path[i].end]) {
				l = sets[path[i].end];
				for (j = 1; j <= n; j++) {
					if (sets[j] == l) sets[j] = sets[path[i].start];
				}
			}
			else {
				l = sets[path[i].start];
				for (j = 1; j <= n; j++) {
					if (sets[j] == l) sets[j] = sets[path[i].end];
				}
			}
			k++;
			if (k < n - 1) cout << path[i].start << " " << path[i].end << " " << path[i].value << endl;
			else cout << path[i].start << " " << path[i].end << " " << path[i].value;
		}
	}
	return 0;
}