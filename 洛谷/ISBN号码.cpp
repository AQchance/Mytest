#include<stdio.h>
int main()
{
	char code[14] = { '\0' };
	scanf("%s", &code);
	int i, j = 1, sum = 0, k;
	for (i = 0; code[i] != '\0'&&j<=9; i++) {
		if (code[i] == '-') continue;
		else {
			sum += (code[i] - 48) * j;
			j++;
		}
	}
	k = sum % 11;
	if (k <= 9) {
		if (k == code[12] - 48) printf("Right");
		else {
			code[12] = k + 48;
			printf("%s", code);
		}
	}
	if (k == 10) {
		if (code[12] == 'X') printf("Right");
		else {
			code[12] = 'X';
			printf("%s", code);
		}
	}
	return 0;
}