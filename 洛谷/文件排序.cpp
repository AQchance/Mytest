#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int n, i, j, l, k;
	int number[100] = { 0 };
	int size[100] = { 0 };
	char use[100] = { '\0' };
	char time[100][25] = { {'\0'},{'\0'} };
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++) {
		gets_s(time[i]);
	}
	for (i = 0; i < n; i++) {
		for (k = 0; k<4; k++) number[i] += (time[i][3 - k] - 48) * pow(10, 4.0 + k);
		if (time[i][6] == '/' && time[i][8] == ' ') number[i] += (time[i][5] - 48) * 100 + time[i][7] - 48;
		else if (time[i][6] == '/' && time[i][9] == ' ') number[i] += (time[i][5] - 48) * 100 + (time[i][7] - 48) * 10 + time[i][8] - 48;
		else if (time[i][7] == '/' && time[i][9] == ' ') number[i] += (time[i][5] - 48) * 1000 + (time[i][6] - 48) * 100 + time[i][8] - 48;
		else if (time[i][7] == '/' && time[i][10] == ' ') number[i] += (time[i][5] - 48) * 1000 + (time[i][6] - 48) * 100 + (time[i][8] - 48) * 10 + time[i][9] - 48;
		for (j = 0; time[i][j] != ' '; j++) {}
		j++;
		for (; time[i][j] != '\0'; j++) {
			size[i] *= 10;
			size[i] += time[i][j] - 48;
		}
	}
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1, k = i; j < n; j++) {
			if (number[j] > number[k]) k = j;
			else if (number[j] == number[k] && size[j] > size[k]) k = j;
		}
		if (i != k) {
			strcpy(use, time[i]);
			strcpy(time[i], time[k]);
			strcpy(time[k], use);
			l = number[i]; number[i] = number[k]; number[k] = l;
			l = size[i]; size[i] = size[k]; size[k] = l;
		}
	}
	for (i = 0; i < n; i++) {
		printf("%s\n", time[i]);
	}
	return 0;
}