#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct tree {
	int data;
	struct tree* lchild, * rchild;
}*BiTree, Tree;
void CreateBST(BiTree& T, int a[], int n) {
	int i, j;
	T = (BiTree)malloc(sizeof(Tree));
	T->lchild = NULL;
	T->rchild = NULL;
	T->data = a[0];
	BiTree t = T;
	for (i = 1; i < n; i++) {
		BiTree temp;

		while (t) {
			if (a[i] < t->data) {
				temp = t;
				t = t->lchild;
			}
			else if (a[i] > t->data) {
				temp = t;
				t = t->rchild;
			}
		}//�ҵ��Ǹ���Ӧ�÷ŵ������һ�����������������������Ҫ�ҵ��÷������������ǰ����
		//������Ҫһ��������ָ��������ǰ�� 
		t = (BiTree)malloc(sizeof(Tree));
		if (a[i] < temp->data) {
			t->data = a[i];
			t->lchild = NULL;
			t->rchild = NULL;
			temp->lchild = t;
		}
		else if (a[i] > temp->data) {
			t->data = a[i];
			t->lchild = NULL;
			t->rchild = NULL;
			temp->rchild = t;//����൱����������һ����㣬������൱�ڽ���ֻ���½���һ����㣬����û�����ӵ����ϡ� 
		}
		t = T;//while��Ϊ���ҵ��Ǹ�λ��ÿ�ζ���Ҫ�ӿ�ʼ�ҡ� 
	}
}
int compare(BiTree& T, BiTree& t) {
	if (t == NULL && T == NULL) {//����null����˵������ͬ������1 
		return 1;
	}
	if (T->data == t->data) {
		if (compare(T->lchild, t->lchild) == 0) {
			return 0;//ֻ�в�ͬ����0 ��ʱ�򷵻�0 
		}
		else if (compare(T->rchild, t->rchild) == 0) {
			return 0;
		}
		return 1;//���Ҷ�������0 ˵�������ok 
	}
	else if (T->data != t->data)
		return 0;
}
//���compareд�ıȽϺ�Ŷ 
int main() {
	int i, j, n, k = 0;
	int b[300] = { 0 };
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		int len = 0;
		getchar();
		char temp[30];
		gets(temp);
		int A[30], TEMP[30];
		for (i = 0; i < strlen(temp); i++) {
			TEMP[i] = temp[i] - '0';
		}
		BiTree T;
		CreateBST(T, TEMP, strlen(temp));
		
		//������취����֤�ҵ����������ĿҪ������������������������һ������1����ʾyes��0��ʾno������ٶ�����һ��0�� 
		for (i = 0; i < n; i++) {
			char a[30];
			gets(a);
			for (j = 0; j < strlen(a); j++) {
				A[j] = a[j] - '0';
			}
			BiTree t;
			CreateBST(t, A, strlen(a));
			if (compare(T, t) == 1) {//������ͬ 
				b[k] = 1;
				k++;
			}
			else {
				b[k] = 0;
				k++;
			}
		}//�½���һ��������ѭ��һ�κ��ˢ���� 
		//int nothing;
		//scanf("%d", &nothing);//�����Ŀ�е����ף���Ȼ���Ѿ�����nΪʲôҪ0�أ� 
	}
	for (i = 0; i < k; i++) {
		if (b[i] == 1) {
			printf("YES\n");
		}
		else if (b[i] == 0) {
			printf("NO\n");
		}
	}
}

