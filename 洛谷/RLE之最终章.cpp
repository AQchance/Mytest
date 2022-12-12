#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//���涨��һ��ѹ������������ѹ�������ļ�
void Compression(char* filename1, char* filename2) {
	FILE* fpfile1;
	FILE* fpfile2;//���������ļ�ָ��
	int i = 0, j;
	char file1[1000] = { '\0' };
	char file2[1000] = { '\0' };//���������ַ����飬�ֱ����ڴ洢�ļ�1���ļ�2�е�����
	fpfile1 = fopen(filename1, "rb");//�Զ�����ֻ���ķ�ʽ���ļ�1
	fpfile2 = fopen(filename2, "wb");//�Զ�����ֻд�ķ�ʽ���ļ�2
	if (fpfile1 == NULL || fpfile2 == NULL) {
		printf("�ļ���ʧ�ܣ�\n");
	}
	//���ļ�1�е����ݶ�ȡ���������ַ�����file1��
	else {
		while (fscanf(fpfile1, "%c", &file1[i]) != EOF) i++;
		fclose(fpfile1);//ʹ�����ļ��󣬽��ļ��ر�
	}
	//���濪ʼ�����㷨�Ĺ���
	int length, minsize, perfectlength, perfectcount;
	int count = 1;
	int k = strlen(file1);
	while (k > 0) {
		minsize = 1001;
		perfectcount = 1;
		perfectlength = 1;
		//������㷨��Ѱ��һ�ε��ַ����У���ʹ����ѹ���ֶ���ռ�ڴ���С��һ���ַ����Ⱥ͸��ַ��εĸ�������ѹ�������Ž⣩
		for (length = 1; length <= (k + 1) / 2; length++) {
			count = 1;
			char m[500] = { '\0' };
			char n[500] = { '\0' };//���������ַ��������ڴ洢��ʱ����
			strncpy(m, file1, length);//��file1�е�ǰlength���ַ�����m��
			//�����㷨�����ж�length���ȵ��ַ���file1�����������˼���
			while (1) {
				for (i = count * length, j = 0; i < length * (count + 1); i++, j++) {
					n[j] = file1[i];
				}//����ѭ����count*length����count+1��*length�����ݴ�������n�У����Ա�m��n��ͬʱ������ѭ��һֱ�ظ���ֱ���ҵ�һ����m����ͬ���ַ���
				if (strcmp(m, n) == 0) {
					j = -1;
					count++;//m��n��ͬ��count������Ȼ�����ѭ��
				}
				else {
					if (count == 1) {
						break;//count����1����ʱӦ������ѭ������ʱlength���ȵ��ַ�����û�к��ʵ�ѹ����ʽ
					}
					else {
						if (minsize > (k - count * strlen(m) + strlen(m))) {
							minsize = k - count * strlen(m) + strlen(m);
							perfectlength = length;
							perfectcount = count;//�˴���minsize��ָ�������ǽ�length���ȵ��ַ�ѹ����ѹ������µ��ַ��ܳ��ȵ���Сֵ
							//��Ȼÿ��ѭ��ֻ����һ�����Ž⣬��Ӧ��������perfectcount��perfectlength
							break;
						}
						else break;
					}
				}
			}
		}
		//���潫���õ���perfectlength��perfectcount����ʹ��
		if (perfectcount == 1) {
			char dst[500] = { '\0' };
			strncpy(dst, file1, perfectlength);
			strcat(file2, dst);//��ʱperfectlength=1��˵��û���ҵ����ʵ�ѹ����ʽ�����ֱ�ӽ�ͷһ���ַ�����file2�У�ʹ��strcat����
		}
		else if (perfectcount > 1) {//��ʱ��perfectlength>1���ʴ���һ�ֿ���ʹѹ�����ַ������̵�ѹ����ʽ
			int a = strlen(file2);
			if (a == 0) {
				a--;
			}
			else file2[a] = ' ';//����Ϊ�˲��������壬��ѹ����һ�ε�ǰ���ÿո���Ÿ���������ѹ����������[]��װ��ʹЧ������ֱ��
			//�������Ƕ����file1��file2�ֻ��1000���ַ�������ѹ����һƬ���ظ��������Ϊ��λ��
			//�������������������Ϊ���ַ����д������ֲ���������������������
			//���ڿ�ͷ���ܻ���ֿո���������������67-72�еĲ�����ʹ��ͷ���ܴ��ڵĿո񲻸�����
			if (perfectcount < 10) file2[a + 1] = 48 + perfectcount;
			else if (perfectcount >= 10 && perfectcount < 100) {
				file2[a + 1] = 48 + perfectcount / 10;
				file2[a + 2] = 48 + perfectcount % 10;
			}
			else if (perfectcount >= 100) {
				file2[a + 1] = 48 + perfectcount / 100;
				file2[a + 2] = (perfectcount / 10) % 10 + 48;
				file2[a + 3] = perfectcount % 10 + 48;
			}
			strcat(file2, "[");
			char dst[500] = { '\0' };
			strncpy(dst, file1, perfectlength);
			strcat(file2, dst);
			strcat(file2, "]");
		}
		//�����file1�ַ������ǰperfectcount*perfectlength�����ɾ�����ٽ���ѭ��
		for (int a = 0, b = perfectcount * perfectlength; b < k; a++, b++) {
			file1[a] = file1[b];
		}
		for (int a = k - perfectcount * perfectlength; a < k; a++) {
			file1[a] = '\0';
		}
		//ɾ����������ַ�����ĳ���kҲ�����ı� 
		k = k - perfectcount * perfectlength;
	}
	fwrite(file2, 1, strlen(file2), fpfile2);//ʹ��fwrite������file2�е�����д���ļ�2��
	fclose(fpfile2);//�ر��ļ�2
}
void Uncompression(char* filename1, char* filename2) {
	FILE* fpfile1;
	FILE* fpfile2;
	int i = 0, j, k, l, number = 0, flag = 0, index, use=0;
	char file1[1000] = { '\0' };
	char file2[1000] = { '\0' };
	fpfile1 = fopen(filename1, "rb");
	fpfile2 = fopen(filename2, "wb");
	if (fpfile1 == NULL || fpfile2 == NULL) {
		printf("�ļ���ʧ�ܣ�\n");
	}
	else {
		while (fscanf(fpfile1, "%c", &file1[i]) != EOF) i++;
		fclose(fpfile1);
	}//105-119�е�������Compression�������ݿ�ͷ�β������ƣ��ڴ˲���׸��
	//��Ȼ�������ַ����鳤�ȵ�ԭ�򣬸����䳤�ȿ�����Ƴ�������������㷨�������ж�ѹ�����ݵ�λ��
	char dst[1000] = { '\0' };
	for (i = 0; i < 4; i++) {
		if (file1[i] == '[') {
			use = 1; break;
		}
	}
	if ((file1[2] == ' ' && use == 1) || use == 0) {
		for (i = 0; file1[i] != ' ' && file1[i] != '\0'; i++) {
			dst[i] = file1[i];
		}
	}
	strcat(file2, dst);
	//����forѭ���ĺ���˼����ǽ�[]�е������Լ���ǰ�������չ������ʵ�ֽ�ѹ����Ŀ�ģ�ͬʱ����[]�ڲ������ݲ��ı䣬ֱ�Ӵ���file2������
	for (; file1[i] != '\0'; i++) {
		if (file1[i] == '[') {
			for (j = i - 1, index = 1,number=0; file1[j]!=' '&& file1[j] >= '0' && file1[j] <= '9'; j--, index *= 10) {
				number = number + (file1[j]-48) * index;
				if(j==0) break;
			}//�˴���forѭ�����ڻ�ȡ[]ǰ������ֵľ���ֵ
			char m[500] = { '\0' };
			char n[500] = { '\0' };
			for (i=i+1, k = 0; file1[i] != ']'; i++,k++) {
				m[k] = file1[i];
			}//��[]�ڵ����ݴ���m��
			for (k = 0; k < number; k++) {
				strcat(file2, m);
			}//�ظ���m���ӵ�file2β�����ظ�����Ϊnumber
			i++;
			for (k = i,l=0; file1[k] != ' ' && file1[k] != '\0'; k++,l++) {
				n[l] = file1[k];
			}
			strcat(file2, n);//����ѹ���������ӵ�file2β��
		}
	}
	fwrite(file2, 1, strlen(file2), fpfile2);//ʹ��fwrite������file2�е�����д���ļ�2��
	fclose(fpfile2);//�ر��ļ�2
}
//�����Ƕ������в�����ʹ��
int main(int argc, char** argv)
{
	if (strcmp(argv[2], "-c") == 0) {
		Compression(argv[1], argv[3]);
		printf("�ļ�ѹ�����!");
	}
	else if (strcmp(argv[2], "-d") == 0) {
		Uncompression(argv[1], argv[3]);
		printf("�ļ���ѹ�����!");
	}
	return 0;
}


