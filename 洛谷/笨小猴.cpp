#include<bits/stdc++.h>
using namespace std;

bool isprime(int i) {
	int j = 0;
	if (i < 2) return 0;
	else if (i < 4) return 1;
	for (j = 2; j <= sqrt(i); j++) {
		if (i % j == 0) return 0;
	}
	return 1;
}
int maxnumber(int a[],int size){
	int i, j;
	j = a[0];
	for (i = 0; i < size; i++) {
		if (a[i] > j) j = a[i];
	}
	return j;
}
int minnumber(int a[], int size) {
	int i, j;
	j = 100;
	for (i = 0; i < size; i++) {
		if (a[i] < j && a[i] != 0) j = a[i];
	}
	return j;
}
int main()
{
	int i, j, k, l, maxn, minn;
	int count[26] = { 0 };
	string s;
	cin >> s;
	for (i = 0; i < s.length(); i++) {
		j = s[i] - 'a';
		count[j]++;
	}
	maxn = maxnumber(count, 26);
	minn = minnumber(count, 26);
	k = maxn - minn;
	if (isprime(k)) {
		cout << "Lucky Word" << endl;
		cout << k;
	}
	else {
		cout << "No Answer" << endl;
		cout << "0";
	}
	return 0;
}
