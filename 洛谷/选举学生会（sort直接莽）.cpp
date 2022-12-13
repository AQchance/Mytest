#include<iostream>
#include<algorithm>
#include<malloc.h>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int* a = (int*)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	sort(a, a + m);
	for (int i = 0; i < m; i++) {
		cout<< a[i]<<" ";
	}
	return 0;
}
