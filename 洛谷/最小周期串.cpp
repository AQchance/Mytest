#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	int i, j, k, l, m, n;
	cin >> s;
	k = s.length();
	while (1) {
		for (j = 1; j <= k; j++) {
			if (k % j != 0) continue;
			else {
				for (i = 0; i < k / j; i++) {
					for (l = 0; l < j; l++) {
						if (s[l] == s[l + i * j]) {
							if (i == k / j - 1 && l == j - 1) {
								cout << j;
								return 0;
							}
							else continue;
						}
						else {
							i = k / j; break;
						}
					}
				}
			}
		}
	}
	return 0;
}