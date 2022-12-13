#include<iostream>
#include<algorithm>
#include<cmath>
#include<malloc.h>
#include<cstdio>
using namespace std;
struct Position {
	int x;
	int y;
	int z;
};
bool cmp(Position a, Position b) {
	return a.z < b.z;
}
int x2(int x) {
	return x * x;
}
int main()
{
	int N, i, j;
	double sums = 0;
	cin >> N;
	Position* position = (Position*)malloc(sizeof(Position) * N);
	for (i = 0; i < N; i++)
	{
		cin >> position[i].x >> position[i].y >> position[i].z;
	}
	sort(position, position + N, cmp);
	for (i = 0; i < N-1; i++) {
		j = x2((position[i].x - position[i + 1].x)) + x2((position[i].y - position[i + 1].y)) + x2((position[i].z - position[i + 1].z));
		sums+= sqrt(j);
	}
	printf("%.3lf", sums);
	return 0;
}