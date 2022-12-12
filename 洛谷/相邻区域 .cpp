#include<stdio.h>
int main()
{
	int m, n, i, j, k, t;
	int a[22][22] = { {0},{0} };
	int min_i = 20, min_j = 20, max_i = 0, max_j = 0;
	scanf("%d %d %d %d", &m, &n, &t, &k);
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			if (a[i][j] == k) {
				if (min_i > i) min_i = i;
				if (max_i < i) max_i = i;
				if (min_j > j) min_j = j;
				if (max_j < j) max_j = j;
			}
		}
	}
	int count1,count2,count3,count4;
	if (a[min_i - 1][min_j] == 0) count1 = 0;else{
		count1=1;
	}
	 if (a[max_i + 1][min_j] == 0) count2 = 0;else{
	 	count2=1;
	 }
	 if (a[min_i][min_j-1] == 0) count3 = 0;else{
	 	count3=1;
	 }
	 if (a[min_i][max_j+1] == 0) count4 = 0;else{
	 	count4=1;
	 }
	
	for (j = min_j; j < max_j; j++) {
		
		 if (a[min_i - 1][j] != a[min_i-1][j + 1]&&a[min_i-1][j + 1]!=0) count1++;
		
		 if (a[max_i + 1][j] != a[max_i+1][j + 1]&&a[max_i+1][j + 1]!=0) count2++;
	}
	for (i = min_i; i < max_i; i++) {
		
		if (a[i][min_j-1] != a[i+1][min_j-1]&& a[i+1][min_j - 1] != 0) count3++;
		
		if (a[i][max_j+1] != a[i+1][max_j+1]&&a[i+1][max_j+1] != 0) count4++;
	}
	printf("%d", count1 + count2 + count3 + count4);
	return 0;
}

