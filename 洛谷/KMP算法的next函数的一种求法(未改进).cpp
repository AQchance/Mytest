#include <bits/stdc++.h>

using namespace std;

int GetNext(string s, int next[], int j) {
	if (j == 0) return -1;
	if (j == 1) return 0;
	int k = next[j - 1];
	while (1) {
		if (k == -1) {
			return 0;
		}
		else {
			if (s[k] == s[j-1]) {
				return k + 1;
			}
			else k = next[k];
		}
	}
}
int main()
{
	int next[50] = { 0 };
	string s = "abaabcac";
	for (int i = 0; i < s.length(); i++) {
		next[i] = GetNext(s, next, i);
	}
	for (int i = 0; i < s.length(); i++) {
		cout << next[i] << " ";
	}
	return 0;
}
