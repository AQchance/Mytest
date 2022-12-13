#include<stdio.h>
int main()
{
	int a, b, n;
	int exit;
	int i, j;
	scanf("%d %d", &a, &b);
	if (a % 2 == 0) {
		a++;
	}
	for (j = a; j <= b; j += 2) {
		exit = 0;
		for (i = 2; i < j / 2; i++) {
			if (j % i == 0) {
				exit = 1;
				break;
			}
			else {
				continue;
			}
		}
		if (exit == 0) {
			if (j <= 9) {
				printf("%d\n", j);
			}
			else if (j > 9) {
				n = j;
				int d1, d2, d3, d4, d5, d6, d7, d8, d9;
				d1 = n % 10;
				n /= 10;
				d2 = n % 10;
				n /= 10;
				d3 = n % 10;
				n /= 10;
				d4 = n % 10;
				n /= 10;
				d5 = n % 10;
				n /= 10;
				d6 = n % 10;
				n /= 10;
				d7 = n % 10;
				n /= 10;
				d8 = n % 10;
				n /= 10;
				d8 = n % 10;
				n /= 10;
				d9 = n % 10;
				if (d9 != 0) {
					if (d1 == d9 && d2 == d8 && d3 == d7 && d6 == d4) {
						printf("%d\n", j);
					}
				}
				else {
					if (d8 != 0) {
						if (d1 = d8 && d2 == d7 && d3 == d6 && d4 == d5) {
							printf("%d\n", j);
						}
					}
					else {
						if (d7 != 0) {
							if (d1 == d7 && d2 == d6 && d3 == d5) {
								printf("%d\n", j);
							}
						}
						else {
							if (d6 != 0) {
								if (d1 == d6 && d2 == d5 && d3 == d4) {
									printf("%d\n", j);
								}
							}
							else {
								if (d5 != 0) {
									if (d1 == d5 && d2 == d4) {
										printf("%d\n", j);
									}
								}
								else {
									if (d4 != 0) {
										if (d4 == d1 && d2 == d3) {
											printf("%d\n", j);
										}
									}
									else {
										if (d3 != 0) {
											if (d1 == d3) {
												printf("%d\n", j);
											}
										}
										else {
											if (d2 != 0) {
												if (d1 == d2) {
													printf("%d\n", j);
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}