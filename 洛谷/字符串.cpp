#include<stdio.h>
int main()
{
	char name[100]={0};
	int i;
	int sum=0;
	gets(name);
	for(i=0;i<100;i++){
		sum+=name[i];
	}
	sum=sum%256;
	printf("%d",sum);
	return 0;
}
