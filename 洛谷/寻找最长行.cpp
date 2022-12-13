#include<stdio.h>
#include<string.h>
int main()
{
	char a[100] = {'\0'};
	int max = 0, i;
	char b[] = "***end***";
	char c[100] = {'\0'};
	while (1) {
		gets_s(a);
		if (strcmp(a, b) == 0) break;
		if (strlen(a) > max) {
			max = strlen(a);
			strcpy(c, a);
		}
	}
	printf("%d\n%s", max,c);
	return 0;
}