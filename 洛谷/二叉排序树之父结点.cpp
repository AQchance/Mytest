#include<stdio.h>
#include<stdlib.h> 
#include<iostream>
using namespace std;

typedef struct tree {
	int data;
	struct tree* lchild, * rchild;
}*BiTree, Tree;
BiTree Insert(BiTree& T, int a) {
	if (!T) {//�ǿյĻ����½�һ���� 
		T = (BiTree)malloc(sizeof(Tree));
		T->data = a;
		T->lchild = NULL;
		T->rchild = NULL;
	}
	else {//����д�С�Ĳ��죬��ô�Ͱ��൱�ڰ�������������һ���µ�����������������������һ�����ܻ���ֿ�
   //��ʱ����½�һ������������ 
		if (a < T->data) {
			T->lchild = Insert(T->lchild, a);
		}
		else if (a > T->data) {
			T->rchild = Insert(T->rchild, a);
		}
	}
	return T;
}

int Find(BiTree T, int a) {//�ҵ��Ǹ����ڵ� 
	BiTree temp;
	temp = T;
	while (T) {
		if (a > T->data) {
			temp = T;
			T = T->rchild;
		}
		else if (a < T->data) {
			temp = T;
			T = T->lchild;
		}
		else {
			return temp->data;
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int i;
	BiTree T = 0;
	for (i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		Insert(T, a);
		if (i == 0)  printf("-1\n");
		else      printf("%d\n", Find(T, a));
	}
	return 0;
}
