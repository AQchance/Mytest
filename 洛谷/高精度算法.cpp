#include<stdio.h>
#include<string.h>
int main()
{
	char number_1[100] = { '\0' };
	char number_2[100] = { '\0' };
	char number_3[100] = { '\0' };//���������ַ����飬�������볤�����֣����е����ַ��������ڽ���
	int number[100] = { 0 };//����һ����ĿҪ����������飬����������Ԫ�س�ʼ��Ϊ0
	int i, j, k, l, length_1, length_2, use=0, m=0;//����һЩ��������
	char symbol;//�����������
	scanf("%s", &number_1);
	getchar();
	scanf("%c", &symbol);
	scanf("%s", &number_2);
	length_1 = strlen(number_1);
	length_2 = strlen(number_2);//�ֱ����ַ����麯����������ַ�����ĳ���
	m = strcmp(number_1, number_2);
	if (length_1 > length_2 || (length_1 == length_2 && m > 0)) use = 1;//��һ�������ڵڶ�����
	else if (length_1 == length_2 && m == 0) use = 0;//��һ�������ڵڶ�����
	else if (length_1 < length_2 || (length_1 == length_2 && m < 0)) use = -1;//��һ����С�ڵڶ�����
	if (use<0) {
		strcpy(number_3, number_2);
		strcpy(number_2, number_1);
		strcpy(number_1, number_3);
		i = length_1; length_1 = length_2; length_2 = i;
	}//����һ����С�ڵڶ�����ʱ������������������ݣ�ͬʱ����������Ϣ�����������������ֵ�λ�ã�������ԭ���Ĵ�С��ϵ��use��ʾ
	if (symbol == '+') {       //���������ʱ�������´���
		for (i = length_1, j = length_1 - 1, k = length_2 - 1; j >= 0; i--, k--, j--) {//�����������п��ٳ�length_1+1���ȣ���������������ֵ����λ����һλ����ΪҪ���ǽ�λ
			if (k >= 0) number[i] += number_1[j] + number_2[k] - 96;//�ӽ�С�����ĸ�λ��ʼ�ֱ�������ĸ���λ����ӣ�ֱ�������λ��
			else number[i] += number_1[j] - 48;//��С�����Ѵ����λ������ֱ�ӽ�����������λƽ������
			if (number[i] > 9) {//����Ӧλ����Ӵ���10��Ӧ����λ
				number[i] %= 10;
				number[i - 1]++;
			}
		}
		if (number[0] == 0) {
			for (i = 1; i <= length_1; i++) { printf("%d", number[i]); }
		}//���λû�н�λ����������Ԥ������λ��û���õ�����number[0]����0�����Դ�i=1��ʼ���
		else {
			for (i = 0; i <= length_1; i++) { printf("%d", number[i]); }
		}//���λ��λ�ˣ�Ԥ�������λ�ò�Ϊ0���ʴ�ͷ���
	}
	else if (symbol == '-') {  //��ʱ����Ϊ��������Ҫ�����Ƿ��Ϊ����
		if (use == 0) printf("0");//��ʱ��һ�������ڵڶ�������ֱ�����0
		else {
			for (i = length_1, j = length_1 - 1, k = length_2 - 1; j >= 0; j--, k--, i--) {
				if (k >= 0) number[i] += number_1[j] - number_2[k];//ģ����ʽ����С����λ���Ӹ�λ�������λ��
				else number[i] += number_1[j] - 48;//���������Ѿ���ɣ��������ĸ�λ��ֱ��ƽ������
				if (number[i] < 0) {
					number[i] += 10;
					number[i - 1]--;
				}//�����λ���
			}
			for (l = 0; l <= length_1; l++) {
				if (number[l] != 0) break;
			}//ͬ��Ԥ����λ�ã���Ԥ����λ����0��������������ò����������ǰ������˶��ٸ�0
			if (use == -1) printf("-");//use=-1��ʾ��һ����С�ڵڶ��������ʲ�ֵΪ�������һ������
			for (i = l; i <= length_1; i++) {
				printf("%d", number[i]);
			}//����������
		}
	}
	return 0;//���
}
