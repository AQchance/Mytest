#include<cstdio>
#include<iostream>
#include<algorithm>
#include<malloc.h>
using namespace std;
int main()
{
	int N, i, j, sumx=0;
	cin >> N;
	int *carriage = (int*)malloc(4 * N);
	for (i = 0; i < N; i++) {
		cin >> carriage[i];
	}
	for (i = 1; i < N; i++) {
		for (j = 0; j < i; j++) {
			if (carriage[j] > carriage[i]) sumx++;
		}
	}
	cout << sumx;
	return 0;
}