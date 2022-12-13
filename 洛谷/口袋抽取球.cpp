#include<stdio.h>
int main()
{
	int x, y, z;
	for (x = 0; x <= 3; x++) {
		for (y = 0; y <= 4; y++) {
			for (z = 0; z <= 5; z++) {
				if (x + y + z == 8) printf("%d %d %d\n", x, y, z);
			}
		}
	}
	return 0;
}