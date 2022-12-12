#include<stdio.h>
#include<string.h>
int main()
{
	int m, n, i, j, l, k;
	char information[200][30] = { {'\0'},{'\0'} };
	char use[30];
	int sumscore[200] = { 0 };
	int English[200] = { 0 };
	int number[200] = { 0 };
	scanf("%d %d", &m, &n);
	getchar();
	for (i = 0; i < m; i++) {
		gets_s(information[i]);
	}
	for (i = 0; i < m; i++) {
		for (j = 2; information[i][j]!=' '; j++) {
			number[i] *= 10;
			number[i] += information[i][j] - 48;
		}
		j++;
		for (; information[i][j] != ' '; j++) {
			sumscore[i] *= 10;
			sumscore[i] += information[i][j] - 48;
		}
		j++;
		for (; information[i][j] != '\0'; j++) {
			English[i] *= 10;
			English[i] += information[i][j] - 48;
		}
	}
	for (i = 0; i < m - 1; i++) {
		for (j = i + 1, k = i; j < m; j++) {
			if (sumscore[j] > sumscore[k]) k = j;
			else if (sumscore[j] == sumscore[k] && English[j] > English[k]) k = j;
			else if (sumscore[j] == sumscore[k] && English[j] == English[k] && number[j] < number[k]) k = j;
		}
		if (i != k) {
			strcpy(use, information[i]);
			strcpy(information[i], information[k]);
			strcpy(information[k], use);
			l = sumscore[i]; sumscore[i] = sumscore[k]; sumscore[k] = l;
			l = English[i]; English[i] = English[k]; English[k] = l;
			l = number[i]; number[i] = number[k]; number[k] = l;
		}
	}
	for (i = 0; i < n; i++) {
		printf("%s\n",information[i]);
	}
	return 0;
}