#include<stdio.h>
#include<stdlib.h> 
#include<iostream>
using namespace std;

typedef struct tree {
	int data;
	struct tree* lchild, * rchild;
}*BiTree, Tree;
BiTree Insert(BiTree& T, int a) {
	if (!T) {//是空的话就新建一个树 
		T = (BiTree)malloc(sizeof(Tree));
		T->data = a;
		T->lchild = NULL;
		T->rchild = NULL;
	}
	else {//如果有大小的差异，那么就把相当于把左子树看作是一个新的树，把这个结点插入这个新树一样，总会出现空
   //这时候就新建一个结点来存这个 
		if (a < T->data) {
			T->lchild = Insert(T->lchild, a);
		}
		else if (a > T->data) {
			T->rchild = Insert(T->rchild, a);
		}
	}
	return T;
}

int Find(BiTree T, int a) {//找到那个父节点 
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
