#include<set>
#include<iostream>
#include<malloc.h>
#include<algorithm>
using namespace std;
int main()
{
	set<int>s;
	int n, i;
	cin >> n;
	int* num = (int*)malloc(4 * n);
	for (i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (i = 0; i < n - 1; i++) {
		int j = num[i] - num[i + 1];
		if (j < 0) j = -j;
		s.insert(j);
	}
	if (*s.begin() == 1 && *(--s.end()) == n - 1) {
		cout << "Jolly";
	}
	else cout << "Not jolly";
	return 0;
}