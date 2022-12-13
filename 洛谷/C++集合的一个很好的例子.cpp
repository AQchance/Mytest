#include<iostream>
#include<set>
using namespace std;
int main()
{
	set<int>s;
	int N;
	cin >> N;
	int j;
	for (int i = 0; i < N; i++) {
		cin >> j;
		s.insert(j);
	}
	cout << s.size()<<endl;
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	return 0;
}