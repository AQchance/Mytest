#include<stdio.h>
int main()
{
	int N, M, i, j, k, l, x, y, exit[50] = { 0 }, max[50] = { 0 };
	int number[11] = { 0 };
	struct AREA {
		int x1;
		int x2;
		int y1;
		int y2;
	};
	AREA area[10];
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		number[i] = i;
	}
	for (i = 0; i < N; i++) {
		scanf("%d %d %d %d", &area[i].x1, &area[i].y1, &area[i].x2, &area[i].y2);
	}
	for (i = 0; i < M; i++) {
		scanf("%d %d", &x, &y);
		for (j = 0; j < N; j++) {
			if (x >= area[j].x1 && x <= area[j].x2 && y >= area[j].y1 && y <=area[j].y2) {
				exit[i] = 1;
				if (number[max[i]] < number[j + 1]) max[i] = j + 1;
			}
		}
		for (l = 1; l <= N; l++) {
			if (number[l] > number[max[i]]) number[l]--;
		}
		number[max[i]] = N;
	}
	for (i = 0; i < M; i++) {
		if (exit[i] == 0) printf("IGNORED\n");
		else printf("%d\n", max[i]);
	}
	return 0;
}