#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s1, s2;
	int n, i;
	cin >> n;
	cin >> s1;
	for (i = n - 1; i >=n/2; i--) {
		if (s1[n - 1 - i] == s1[i]) continue;
		else {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}