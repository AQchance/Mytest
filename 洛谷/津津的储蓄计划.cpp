#include<stdio.h>
int main()
{
	int moneyofmother = 0, precharge[12] = { 0 };
	int i, j, k;
	for (i = 0; i < 12; i++) {
		scanf("%d", &precharge[i]);
	}
	for (i = 0; i < 12;i++){
		if ((i == 0 && 300 < precharge[i])||(i>0&&precharge[i] > 300+precharge[i-1])) {
			printf("-%d", i + 1);
			return 0;
		}
		else {
			if (i == 0) {
				k= ((300 - precharge[i]) / 100) * 100;
				moneyofmother += k;
				precharge[i] = (300 - precharge[i]) - k;
			}
			else {
				k = ((300 + precharge[i - 1] - precharge[i]) / 100) * 100;
				moneyofmother += k;
				precharge[i] = (300 + precharge[i - 1] - precharge[i]) - k;;
			}
		}
	}
	printf("%.0lf", 1.2 * moneyofmother+precharge[11]);
	return 0;
}