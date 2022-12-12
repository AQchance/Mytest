#include<stdio.h>
#include<malloc.h>
int maxnumber(int a[],int size) {
	int max = 0;
	for (int i = 0; i < size; i++) {
		if (max < a[i]) max = a[i];
	}
	return max;
}
int minnumber(int a[], int size) {
	int min = a[0];
	for (int i = 0; i < size; i++) {
		if (min > a[i]) min = a[i];
	}
	return min;
}
int main()
{
	int n,sum = 0;
	double average;
	scanf("%d", &n);
	int* number = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &number[i]);
	}
	for (int i = 0; i < n; i++) {
		sum += number[i];
	}
	average = (sum - maxnumber(number, n) - minnumber(number, n))*1.0 / (n - 2);
	printf("%.2lf", average);
	return 0;
}