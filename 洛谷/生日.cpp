#include<iostream>
#include<algorithm>
#include<string>
#include<malloc.h>
using namespace std;
struct Person{
	int birthyear, birthmonth, birthday;
	string name;
	int id;
};
bool cmp(Person a, Person b) {
	int i = a.birthyear * 10000 + a.birthmonth * 100 + a.birthday;
	int j = b.birthyear * 10000 + b.birthmonth * 100 + b.birthday;
	if (i > j) return 0;
	else if (i < j) return 1;
	else return a.id > b.id;
}
int main()
{
	int n, i, j;
	cin >> n;
	Person person[100];
	for (i = 0; i < n; i++) {
		person[i].id = i;
		cin >> person[i].name;
		cin >> person[i].birthyear;
		cin >> person[i].birthmonth;
		cin>> person[i].birthday;
	}
	sort(person, person + n, cmp);
	for (i = 0; i < n; i++) {
		cout << person[i].name<<endl;
	}
	return 0;
}