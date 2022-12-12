#include<iostream>
#include<algorithm>
#include<malloc.h>
#include<cmath>
using namespace std;
struct Employee {
	int id;
	int score;
};
bool cmp(Employee a, Employee b) {
	if (a.score > b.score) return 1;
	else if (a.score == b.score && a.id < b.id) return 1;
	else return 0;
}
int main()
{
	int n, k, i, j;
	cin >> n >> k;
	Employee* employee = (Employee*)malloc(sizeof(Employee) * n);
	for (i = 0; i < n; i++) {
		cin >> employee[i].id >> employee[i].score;
	}
	sort(employee, employee + n,cmp);
	k = floor(k * 1.5);
	for (i = k - 1; i < n - 1; i++) {
		if (employee[i].score != employee[i + 1].score) break;
	}
	cout << employee[i].score<<" "<< i + 1 << endl;
	for (j = 0; j < i+1; j++) {
		cout << employee[j].id << " " << employee[j].score << endl;
	}
	return 0;
}