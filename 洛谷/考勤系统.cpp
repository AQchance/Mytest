#include<stdio.h>
int main()
{
	int n, i, j, k, count = 0, l, a, b;
	int time[101] = { 0 };
	int num[101] = { 0 };
	scanf("%d", &n);
	struct student{
		int number;
		char t1[6] = { '\0' };
		char t2[6] = { '\0' };
	};
	student stud[100];
	for (i = 0; i < n; i++) {
		scanf("%d %s %s", &stud[i].number, &stud[i].t1, &stud[i].t2);
		getchar();
	}
	for (i = 0; i < n; i++) {
		a = stud[i].number;
		time[a] += ((stud[i].t2[0] - 48) * 10 + stud[i].t2[1] - (stud[i].t1[0] - 48) * 10 - stud[i].t1[1]) * 60 + (stud[i].t2[3] - 48) * 10 + stud[i].t2[4] - (stud[i].t1[3] - 48) * 10 - stud[i].t1[4];
	}
	i = 0;
	while (i < 101) {
		if (time[i] != 0) count++;
		i++;
	}
	for (i = 1; i<=count; i++) {
		for (j = 1, k = 1; j < 101; j++) {
			if (time[j] > time[k]) k = j;
			else if (time[j] == time[k] && j < k) k = j;
		}
		printf("%d %d\n", k, time[k]);
		time[k] = 0;
	}
	return 0;
}
