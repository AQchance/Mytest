#include <iostream>
using namespace std;

int max_num(int x, int y, int z = 0) {
	int i = max(x, y);
	int j = max(x, z);
	return max(i, j);
}

int main()
{
	int n, i, a[3] = { 0 };
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n == 2) {
		cout << max_num(a[0], a[1]);
	}
	else cout << max_num(a[0], a[1], a[2]);
	return 0;
}