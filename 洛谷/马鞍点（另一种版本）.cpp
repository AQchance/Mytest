#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

struct Point {
	int i;
	int j;
	int value;
};

bool cmp(struct Point a, struct Point b) {
	if (a.i < b.i) return 1;
	else if (a.i > b.i) return 0;
	else if (a.i == b.i && a.j < b.j) return 1;
	else return 0;
}

int main()
{
	int m, n, i, j, k, l, r, s;
	int exit;
	int count = 0;
	struct Point point[100];
	scanf("%d %d", &m, &n);
	int a[100][100];
	int b[100];
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 0; i < m; i++) {
		for (j = 1, k = 0; j < n; j++) {
			if (a[i][k] > a[i][j]) k = j;
		}
		exit = 1;
		for (r = 0; r < m; r++) {
			if (a[r][k] > a[i][k]) {
				exit = 0;
				break;
			}
		}
		if (exit == 1) {
			point[count].i = i+1;
			point[count].j = k+1;
			point[count].value = a[i][k];
			count++;
		}
	}
	if (count == 0) printf("no\n");
	else {
		sort(point, point + count, cmp);
		for (i = 0; i < count; i++) {
			cout << point[i].i << " " << point[i].j << " " << point[i].value << endl;
		}
	}
	return 0;
}