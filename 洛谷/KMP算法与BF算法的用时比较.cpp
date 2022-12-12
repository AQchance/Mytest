#include <bits/stdc++.h>

using namespace std;

//int GetNext(string s, int next[], int j) {
//	if (j == 0) return -1;
//	if (j == 1) return 0;
//	int k = next[j - 1];
//	while (1) {
//		if (k == -1) {
//			return 0;
//		}
//		else {
//			if (s[k] == s[j - 1]) {
//				return k + 1;
//			}
//			else k = next[k];
//		}
//	}
//}
int main()
{
	clock_t start, finish;
	double duration;
	start = clock();
	/*int next[50] = { 0 };
	string s = "abaabcac", S = "abeechfabaacabaabcacac";
	for (int i = 0; i < s.length(); i++) {
		next[i] = GetNext(s, next, i);
	}
	for (int i = 0; i < s.length(); i++) {
		cout << next[i] << " ";
	}
	cout << endl;
	int n = 10000;
	while (n > 0) {
		int i = 0, j = 0;
		while (i < S.length() && j < s.length()) {
			if (s[j] == S[i]) {
				i++;
				j++;
			}
			else {
				j = next[j];
				if (j == -1) {
					j = 0;
					i++;
				}
			}
		}
		if (j == s.length()) cout << i - s.length() << endl;
		else cout << "没有对应的子串";
		n--;
	}*/

	int i, j;
	bool find = 0;
	string s="abaabcac", S = "abeechfabaacabaabcacac";
	int n = 10000;
	while (n > 0) {
		for (i = 0; i < S.length() - s.length(); i++) {
			for (j = 0; j < s.length(); j++) {
				int m = i;
				while (S[m] == s[j] && m < S.length() && j < s.length()) {
					m++;
					j++;
				}
				if (j == s.length()) {
					cout << i << endl;
					find = 1;
					goto out;
				}
				else break;
			}
		}
	out:
		if (find == 0) cout << "未找到对应的子串";
		n--;
	}
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%lf seconds\n", duration);
	return 0;
}
