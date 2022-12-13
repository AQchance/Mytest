#include <bits/stdc++.h>

using namespace std;

int num[10] = { 0 };
bool used[10] = { 0 };
int A, B, C;
bool ans = false;
int forms(int n) {
	int i, sum = 0;
	for (i = n * 3-2; i <= n * 3; i++) {
		sum *= 10;
		sum += num[i];
	}
	return sum;
}

void solve(int n) {
	if (n > 9 && forms(1) * B == forms(2) * A && forms(1) * C == forms(3) * A) {
		ans = true;
		cout << forms(1) << " " << forms(2) << " " << forms(3) << endl;
		return;
	}
	for (int i = 1; i <= 9; i++) {
		if (!used[i]) {
			used[i] = true;
			num[n] = i;
			solve(n + 1);
			used[i] = false;
		}
	}
}

int main()
{
	cin >> A >> B >> C;
	solve(1);
	if (!ans) {
		cout << "No!!!";
	}
	return 0;
}