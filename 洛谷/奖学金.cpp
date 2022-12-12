#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct Student {
	int id;
	int mathscore;
	int Chinesescore;
	int Englishscore;
};
const int N = 300;
Student students[N];
bool cmp(Student a, Student b) {
	int suma = a.mathscore + a.Chinesescore + a.Englishscore;
	int sumb = b.Chinesescore + b.mathscore + b.Englishscore;
	if (suma > sumb) return 1;
	else if (suma == sumb && a.Chinesescore > b.Chinesescore) return 1;
	else if (suma == sumb && a.Chinesescore == b.Chinesescore && a.id < b.id) return 1;
	else return 0;
}
int main()
{
	int n, i;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> students[i].Chinesescore >> students[i].mathscore >> students[i].Englishscore;
		students[i].id = i + 1;
	}
	sort(students, students + n, cmp);
	for (i = 0; i < 5&&i<n; i++) {
		printf("%d %d\n", students[i].id, students[i].Chinesescore+students[i].mathscore+students[i].Englishscore);
	}
	return 0;
}