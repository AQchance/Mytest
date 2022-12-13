#include<stdio.h>
#include<string.h>
int main()
{
	char a[51] = {'\0'};
	int i, j, count;
	scanf("%s", &a);
	for (i = 0; a[i] != '\0'; i++) {
		j=i;
		if (a[i] < 48 || a[i]>57) {
			if (a[i + 1] >= 48 && a[i + 1] <= 57) {
				if (a[i + 2] >= 48 && a[i + 2] <= 57) {
					count = (a[i + 1] - 48) * 10 + a[i + 2] - 48;
					i += 2;
				}
				else {
					count = a[i + 1] - 48; 
					i++;
				}
			}
			if (a[j + 1] < 48 || a[j + 1]>57) count = 1;
			for (; count > 0; count--) {
				printf("%c", a[j]);
			}
		}
	}
	return 0;
}

