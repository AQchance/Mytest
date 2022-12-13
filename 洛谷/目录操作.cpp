#include<stdio.h>
#include<string.h>
int main()
{
	char a[201] = { '\0' };
	char b[201] = { '\0' };
	char c[] = "cd /";
	char d[] = "cd ..";
	char e[] = "pwd";
	int i, j, k, count = 0;
	gets_s(a);
	while (1) {
		gets_s(b);
		if (strcmp(b, e) == 0) {
			printf("%s", a);
			break;
		}
		else if (strcmp(b, c) == 0) {
			a[0] = '/';
			for (i = 1; a[i] != '\0'; i++) {
				a[i] = '\0';
			}
		}
		else if (strcmp(b, d) == 0) {
			if (strlen(a) == 1) a[0] = '/';
			else {
				for (i = 0; a[i] != '\0'; i++) {
					if (a[i] == '/') count++;
				}
				if (count == 1) {
					a[0] = '/';
					for (i = 1; a[i] != '\0'; i++) {
						a[i] = '\0';
					}
				}
				else if (count > 1) {
					for (i = strlen(a) - 1; a[i] != '/'; i--) {
						a[i] = '\0';
					}
					if (a[i] != '\0') a[i] = '\0';
				}
			}
		}
		else if (strlen(b) >= 4 && b[3] != '/' && b[3] != '.') {
			k = strlen(a);
			if (k > 1) {
				a[k] = '/';
				for (i = k + 1, j = 3; b[j] != '\0'; i++, j++) {
					a[i] = b[j];
				}
			}
			else if (k == 1) {
				for (i = 1, j = 3; b[j] != '\0'; i++, j++) {
					a[i] = b[j];
				}
			}
		}
		else if (strlen(b) >= 5 && b[3] == '/') {
			for (i = 0; a[i] != '\0'; i++) {
				a[i] = '\0';
			}
			for (i = 0, j = 3; b[j] != '\0'; i++, j++) {
				a[i] = b[j];
			}
		}
	}
	return 0;
}
