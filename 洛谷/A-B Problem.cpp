#include <bits/stdc++.h>

using namespace std;

long ABProblem(int a[],int C,int n) {//此处用long是因为j会超过int的范围，
									 //刷题刷的少，确实应该注意一下边缘数据的AC要求
	int i, k;
	long j = 0;
	map<int, int> mymap;
	for (i = 0; i < n; i++) {
		if (mymap.find(a[i]) != mymap.end()) {
			mymap[a[i]]++;
		}
		else mymap[a[i]] = 1;
	}
	for (i = 0; i < n;i++) {
		k = a[i];
		if (mymap.find(k - C) != mymap.end()) {
			j += mymap[k-C];
		}
	}
	return j;
}

int main()
{
	int n, C;
	int a[200005] = { 0 };
	cin >> n >> C;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << ABProblem(a, C, n);
	return 0;
}