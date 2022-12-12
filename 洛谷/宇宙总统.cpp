#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
struct Vote {
	string votenum;
	int id;
}vote[20];
bool cmp(Vote a, Vote b) {
	if (a.votenum.size() > b.votenum.size()) return 1;
	else if (a.votenum.size() < b.votenum.size()) return 0;
	else {
		if (a.votenum > b.votenum) return 1;
		else return 0;
	}
}
int main()
{
	int n, i, j;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> vote[i].votenum;
		vote[i].id = i + 1;
	}
	sort(vote, vote + n, cmp);
	cout << vote[0].id << endl << vote[0].votenum;
	return 0;
}