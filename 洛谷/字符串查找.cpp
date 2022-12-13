#include<stdio.h>
char fun(char a[300]) {
	int i, count = 0;
	for (i = 0; a[i] != '\0'; i++) {
		if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z')) count++;
	}
	return count;
}
int main()
{
	char a[300];
	scanf("%s", &a);
	printf("%d", fun(a));
	return 0;
}