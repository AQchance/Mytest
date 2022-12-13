#include<iostream>
#include<cstdio>
#include<algorithm>
#include<malloc.h>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int main()
{
	int n, S, i, sumx = 0;
	cin >> n >> S;
	int* height = (int*)malloc(4 * n);
	for (i = 0; i < n; i++) {
		cin >> height[i];
	}
	sort(height, height + n, cmp);
	for (i = 0; i < n; i++) {
		sumx += height[i];
		if (sumx >= S) {
			cout << i + 1 << endl;
			break;
		}
	}
	return 0;
}