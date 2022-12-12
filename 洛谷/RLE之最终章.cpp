#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//下面定义一个压缩函数，用来压缩所给文件
void Compression(char* filename1, char* filename2) {
	FILE* fpfile1;
	FILE* fpfile2;//定义两个文件指针
	int i = 0, j;
	char file1[1000] = { '\0' };
	char file2[1000] = { '\0' };//定义两个字符数组，分别用于存储文件1和文件2中的内容
	fpfile1 = fopen(filename1, "rb");//以二进制只读的方式打开文件1
	fpfile2 = fopen(filename2, "wb");//以二进制只写的方式打开文件2
	if (fpfile1 == NULL || fpfile2 == NULL) {
		printf("文件打开失败！\n");
	}
	//将文件1中的内容读取并储存入字符数组file1中
	else {
		while (fscanf(fpfile1, "%c", &file1[i]) != EOF) i++;
		fclose(fpfile1);//使用完文件后，将文件关闭
	}
	//下面开始核心算法的构建
	int length, minsize, perfectlength, perfectcount;
	int count = 1;
	int k = strlen(file1);
	while (k > 0) {
		minsize = 1001;
		perfectcount = 1;
		perfectlength = 1;
		//下面的算法是寻找一段的字符串中，能使所得压缩字段所占内存最小的一个字符长度和该字符段的个数（即压缩的最优解）
		for (length = 1; length <= (k + 1) / 2; length++) {
			count = 1;
			char m[500] = { '\0' };
			char n[500] = { '\0' };//定义两个字符数组用于存储临时数据
			strncpy(m, file1, length);//将file1中的前length个字符存入m中
			//下面算法用于判断length长度的字符在file1中连续出现了几次
			while (1) {
				for (i = count * length, j = 0; i < length * (count + 1); i++, j++) {
					n[j] = file1[i];
				}//利用循环将count*length到（count+1）*length的内容存入数组n中，并对比m和n，同时，利用循环一直重复，直到找到一段与m不相同的字符串
				if (strcmp(m, n) == 0) {
					j = -1;
					count++;//m和n相同，count自增，然后继续循环
				}
				else {
					if (count == 1) {
						break;//count等于1，此时应该跳出循环，这时length长度的字符串并没有合适的压缩方式
					}
					else {
						if (minsize > (k - count * strlen(m) + strlen(m))) {
							minsize = k - count * strlen(m) + strlen(m);
							perfectlength = length;
							perfectcount = count;//此处的minsize是指，当我们将length长度的字符压缩后，压缩后大致的字符总长度的最小值
							//显然每次循环只会有一个最优解，对应的数据是perfectcount和perfectlength
							break;
						}
						else break;
					}
				}
			}
		}
		//下面将所得到的perfectlength和perfectcount进行使用
		if (perfectcount == 1) {
			char dst[500] = { '\0' };
			strncpy(dst, file1, perfectlength);
			strcat(file2, dst);//此时perfectlength=1，说明没有找到合适的压缩方式，因此直接将头一个字符存入file2中，使用strcat函数
		}
		else if (perfectcount > 1) {//此时的perfectlength>1，故存在一种可以使压缩后字符串更短的压缩方式
			int a = strlen(file2);
			if (a == 0) {
				a--;
			}
			else file2[a] = ' ';//我们为了不产生歧义，在压缩的一段的前面用空格符号隔开，并且压缩的内容用[]包装，使效果更加直观
			//由于我们定义的file1和file2最长只有1000个字符，所以压缩后单一片段重复次数最多为三位数
			//下面讨论三种情况，因为向字符串中存入数字并不是像整型数组那样简单
			//由于开头可能会出现空格，所以我们做了如67-72行的操作，使开头可能存在的空格不复存在
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
		//下面对file1字符数组的前perfectcount*perfectlength项进行删除后再进行循环
		for (int a = 0, b = perfectcount * perfectlength; b < k; a++, b++) {
			file1[a] = file1[b];
		}
		for (int a = k - perfectcount * perfectlength; a < k; a++) {
			file1[a] = '\0';
		}
		//删除若干项后，字符数组的长度k也有所改变 
		k = k - perfectcount * perfectlength;
	}
	fwrite(file2, 1, strlen(file2), fpfile2);//使用fwrite函数将file2中的内容写入文件2中
	fclose(fpfile2);//关闭文件2
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
		printf("文件打开失败！\n");
	}
	else {
		while (fscanf(fpfile1, "%c", &file1[i]) != EOF) i++;
		fclose(fpfile1);
	}//105-119行的内容与Compression函数内容开头段操作相似，在此不做赘述
	//依然是由于字符数组长度的原因，根据其长度可以设计出下面的特殊性算法，进行判断压缩内容的位置
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
	//下面for循环的核心思想就是将[]中的内容以及其前面的数字展开来，实现解压缩的目的，同时不在[]内部的内容不改变，直接存入file2数组中
	for (; file1[i] != '\0'; i++) {
		if (file1[i] == '[') {
			for (j = i - 1, index = 1,number=0; file1[j]!=' '&& file1[j] >= '0' && file1[j] <= '9'; j--, index *= 10) {
				number = number + (file1[j]-48) * index;
				if(j==0) break;
			}//此处的for循环用于获取[]前面的数字的具体值
			char m[500] = { '\0' };
			char n[500] = { '\0' };
			for (i=i+1, k = 0; file1[i] != ']'; i++,k++) {
				m[k] = file1[i];
			}//将[]内的内容存入m中
			for (k = 0; k < number; k++) {
				strcat(file2, m);
			}//重复将m连接到file2尾部，重复次数为number
			i++;
			for (k = i,l=0; file1[k] != ' ' && file1[k] != '\0'; k++,l++) {
				n[l] = file1[k];
			}
			strcat(file2, n);//将非压缩内容连接到file2尾部
		}
	}
	fwrite(file2, 1, strlen(file2), fpfile2);//使用fwrite函数将file2中的内容写入文件2中
	fclose(fpfile2);//关闭文件2
}
//下面是对命令行参数的使用
int main(int argc, char** argv)
{
	if (strcmp(argv[2], "-c") == 0) {
		Compression(argv[1], argv[3]);
		printf("文件压缩完成!");
	}
	else if (strcmp(argv[2], "-d") == 0) {
		Uncompression(argv[1], argv[3]);
		printf("文件解压缩完成!");
	}
	return 0;
}


