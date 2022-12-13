#include<stdio.h>
int main()
{
	int n, i, j, k, p, count = 0, l;
	int number[20][5] = {0};
	scanf("%d", &n);
	for (k = 0; k < n; k++) {
		scanf("%d", &p);
		for (i = 0; i < 20; i++) {
			count = 0;
			for (j = 0; j < 5; j++) {
				if (number[i][j] == 0) count++;
			}
			if (count >= p) {
				for (l = 0; p>0;l++) {
					if (number[i][l] == 0) {
						number[i][l] = 1;
						p--;
						if(p>0) printf("%d ", i * 5 + l + 1);
						else if(p == 0) printf("%d\n",i*5+l+1);
					}
				}
			}
		}
		if (p > 0) {
			for (i = 0; i < 20; i++) {
				for (j = 0; j < 5; j++) {
					if (number[i][j] == 0) {
						number[i][j] = 1;
						printf("%d ", i * 5 + j + 1);
						p--;
					}
					if (p == 0) {
						printf("\n");
						break;
					}
				}
				if (p == 0)break;
			}
		}
	}
	return 0;
}