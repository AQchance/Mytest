#include <bits/stdc++.h>

using namespace std;

int FindFather(int x, int y) {
	if (x == y) return x;
	else if (x > y) {
		return FindFather(x / 2, y);
	}
	else {
		return FindFather(x, y / 2);
	}
}

int main()
{
	int a[200] = { 0 }, i, j = 0, x, y;
	while (1) {
		cin >> x >> y;
		if (x == 0 && y == 0) break;
		else {
			a[j] = FindFather(x, y);
			j++;
		}
	}
	for (i = 0; i < j; i++) {
		cout << a[i] << endl;
	}
	return 0;
}