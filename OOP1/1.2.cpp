#include <iostream>

using namespace std;

void sort_num(int& x, int& y, int& z) {
	if (x > y) swap(x, y);
	if (y > z) swap(y, z);
	if (x > y) swap(x, y);
}

int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	sort_num(x, y, z);
	cout << x << " " << y << " " << z << endl;
	return 0;
}