#include<stdio.h>
#include<string.h>
int main()
{
	char L1[100] = { '\0' };
	char L2[100] = { '\0' };
	int max = 0, i, j, count=0, k, l;
	double same;
	gets_s(L1);
	gets_s(L2);
	for (i = 0; L1[i] != '\0'; i++) {
		if (L1[i] >= 'a' && L1[i] <= 'z') L1[i] -= 'a' - 'A';
	}
	for (i = 0; L2[i] != '\0'; i++) {
		if (L2[i] >= 'a' && L2[i] <= 'z') L2[i] -= 'a' - 'A';
	}
	for (i = 0; L1[i] != '\0'; i++) {
		count = 0;
		for (j = 0; L2[j] != '\0'; j++) {
			if (L1[i] == L2[j]) {
				count = 1;
				for (k = i + 1, l = j + 1; L1[k] != '\0' && L2[l] != '\0'; k++, l++) {
					if (L1[k] == L2[l]) {
						count++;
					}
					else break;
				}
				if (max <= count) max = count;
			}
		}
	}
	same = 1.0 * 2 * max / (strlen(L1) + strlen(L2));
	printf("%.3lf", same);
	return 0;
}