#include<stdio.h>
int main()
{
	int x, y;
	double z;
	for (x = 1; x <= 20; x++) {
		for (y = 0; y <= 33; y++) {
			for (z = 0.0; z <= 100.0; z++) {
				if (x*1.0 + y*1.0 + z == 100.0&&5.0*x+3.0*y+z/3==100.0&&x!=12) printf("%d %d %.0lf\n", x, y, z);
				if (x*1.0 + y*1.0 + z == 100.0&&5.0*x+3.0*y+z/3==100.0&&x==12) printf("%d %d %.0lf", x, y, z);
			}
		}
	}
	return 0;
}

