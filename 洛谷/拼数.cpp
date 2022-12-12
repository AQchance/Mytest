#include<iostream>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
bool cmp(string a, string b) {
	return a + b > b + a;
}
int main()
{
	int n, i;
	string str[20];
	set<string>s;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> str[i];
	}
	sort(str, str + n, cmp);
	for (i = 0; i < n; i++) {
		cout << str[i];
	}
	return 0;
}
