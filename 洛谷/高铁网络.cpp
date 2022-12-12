#include<bits/stdc++.h>

using namespace std;

typedef struct PathInfo {
	int start;
	int end;
}Path;

int main()
{
	int i, j, l = 0, n, m, sets[1000] = { 0 };
	Path path[3000];
	cin >> n >> m;
	for (i = 0; i < m; i++) {
		cin >> path[i].start >> path[i].end;
	}
	for (i = 1; i <= n; i++) {
		sets[i] = i;
	}
	for (i = 0; i < m; i++) {
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
		}
	}
	set<int> s;
	for (i = 1; i <= n; i++) {
		s.insert(sets[i]);
	}
	cout << s.size() - 1;
	return 0;
}