#include <bits/stdc++.h>

using namespace std;

int GetNext(char s[], int next[], int j) {
	if (j == 0) return -1;
	if (j == 1) return 0;
	int k = next[j - 1];
	while (1) {
		if (k == -1) {
			return 0;
		}
		else {
			if (s[k] == s[j - 1]) {
				return k + 1;
			}
			else k = next[k];
		}
	}
}
int main()
{
	int next[200] = { 0 };
	int n;
	char s[200] = { '\0' };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		next[i] = GetNext(s, next, i);
	}
	for (int i = 0; i < n; i++) {
		cout << next[i] << " ";
	}
	return 0;
}
