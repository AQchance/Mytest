#include<stdio.h>
int main()
{
	int n, i, j, k, l;
	int x1, x2, y1, y2, count = 0;
	int min_x=100,min_y=100,max_x=0,max_y=0; 
	int a[100][100] = { {0},{0} };
	scanf("%d", &n);
	while (n > 0) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		if(x1<min_x) min_x=x1;
		if(x2>max_x) max_x=x2;
		if(y1<min_y) min_y=y1;
		if(y2>max_y) max_y=y2;
		for (i = x1 ; i < x2; i++) {
			for (j = y1 ; j < y2; j++) {
				a[i][j] = 1;
			}
		}
		n--;
	}
	for (i = min_x; i <max_x; i++) {
		for (j = min_y; j <max_y; j++) {
			if (a[i][j] == 1) {
				count++;
			}
		}
	}
	printf("%d", count);
	return 0;
}
