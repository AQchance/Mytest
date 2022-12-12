#include<stdio.h>
#include<string.h> 
int main()
{
	char s[200] = {'\0'};
	int i;
	char t[100] = { '\0' }; 
	scanf("%s", &s);
	for (i = 0; s[2 * i] != '\0'; i++) {
		t[i] = s[2 * i];
	}
	printf("%s",t);
	return 0;
}
