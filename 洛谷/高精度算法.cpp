#include<stdio.h>
#include<string.h>
int main()
{
	char number_1[100] = { '\0' };
	char number_2[100] = { '\0' };
	char number_3[100] = { '\0' };//定义三个字符数组，便于输入长串数字，其中第三字符数组用于交换
	int number[100] = { 0 };//定义一个题目要求的整型数组，并将其所有元素初始化为0
	int i, j, k, l, length_1, length_2, use=0, m=0;//定义一些基本变量
	char symbol;//定义运算符号
	scanf("%s", &number_1);
	getchar();
	scanf("%c", &symbol);
	scanf("%s", &number_2);
	length_1 = strlen(number_1);
	length_2 = strlen(number_2);//分别用字符数组函数求出两个字符数组的长度
	m = strcmp(number_1, number_2);
	if (length_1 > length_2 || (length_1 == length_2 && m > 0)) use = 1;//第一个数大于第二个数
	else if (length_1 == length_2 && m == 0) use = 0;//第一个数等于第二个数
	else if (length_1 < length_2 || (length_1 == length_2 && m < 0)) use = -1;//第一个数小于第二个数
	if (use<0) {
		strcpy(number_3, number_2);
		strcpy(number_2, number_1);
		strcpy(number_1, number_3);
		i = length_1; length_1 = length_2; length_2 = i;
	}//当第一个数小于第二个数时，交换两个数组的内容，同时交换长度信息，即交换了两个数字的位置，交换后，原来的大小关系用use表示
	if (symbol == '+') {       //当两数相加时进行如下处理
		for (i = length_1, j = length_1 - 1, k = length_2 - 1; j >= 0; i--, k--, j--) {//在整型数组中开辟出length_1+1长度，比输入的两个数字的最大位数多一位，因为要考虑进位
			if (k >= 0) number[i] += number_1[j] + number_2[k] - 96;//从较小的数的个位开始分别与大数的各个位数相加，直到其最高位数
			else number[i] += number_1[j] - 48;//较小的数已达最高位数，则直接将大数的所在位平移下来
			if (number[i] > 9) {//若对应位数相加大于10，应当进位
				number[i] %= 10;
				number[i - 1]++;
			}
		}
		if (number[0] == 0) {
			for (i = 1; i <= length_1; i++) { printf("%d", number[i]); }
		}//最高位没有进位，所以我们预先留的位置没有用到，即number[0]还是0，所以从i=1开始输出
		else {
			for (i = 0; i <= length_1; i++) { printf("%d", number[i]); }
		}//最高位进位了，预先留存的位置不为0，故从头输出
	}
	else if (symbol == '-') {  //此时运算为减法，需要考虑是否差为负数
		if (use == 0) printf("0");//此时第一个数等于第二个数，直接输出0
		else {
			for (i = length_1, j = length_1 - 1, k = length_2 - 1; j >= 0; j--, k--, i--) {
				if (k >= 0) number[i] += number_1[j] - number_2[k];//模拟竖式，较小的数位数从个位减到最大位数
				else number[i] += number_1[j] - 48;//减法运算已经完成，将大数的高位数直接平移下来
				if (number[i] < 0) {
					number[i] += 10;
					number[i - 1]--;
				}//解决借位情况
			}
			for (l = 0; l <= length_1; l++) {
				if (number[l] != 0) break;
			}//同样预留了位置，若预留的位置是0，不将其输出，该步骤计算数组前面出现了多少个0
			if (use == -1) printf("-");//use=-1表示第一个数小于第二个数，故差值为负，输出一个负号
			for (i = l; i <= length_1; i++) {
				printf("%d", number[i]);
			}//输出计算后结果
		}
	}
	return 0;//完成
}
