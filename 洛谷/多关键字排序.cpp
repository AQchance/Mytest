#include <bits/stdc++.h>

using namespace std;

typedef struct StudentInfo {
	int score;
	int age;
	string name;
}Student;

bool cmp(Student a, Student b) {
	if (a.score > b.score) return 1;
	else if (a.score < b.score) return 0;
	else {
		if (a.name < b.name) return 1;
		else if (a.name > b.name) return 0;
		else {
			return a.age < b.age;
		}
	}
}

int main()
{
	int n, i;
	Student student[100];
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> student[i].name >> student[i].age >> student[i].score;
	}
	sort(student, student + n, cmp);
	for (i = 0; i < n; i++) {
		cout << student[i].name << " " << student[i].age << " " << student[i].score << endl;
	}
	return 0;
}
