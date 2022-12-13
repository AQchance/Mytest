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
		}//找到那个点应该放到哪里，下一步来具体放他，但是现在需要找到该放在那里的他的前驱，
		//所以需要一个单独的指针来保存前驱 
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
			temp->rchild = t;//这个相当于连上了下一个结点，否则就相当于仅仅只是新建了一个结点，但是没有连接到树上。 
		}
		t = T;//while是为了找到那个位置每次都需要从开始找。 
	}
}
int compare(BiTree& T, BiTree& t) {
	if (t == NULL && T == NULL) {//都是null才是说他们相同都返回1 
		return 1;
	}
	if (T->data == t->data) {
		if (compare(T->lchild, t->lchild) == 0) {
			return 0;//只有不同等于0 的时候返回0 
		}
		else if (compare(T->rchild, t->rchild) == 0) {
			return 0;
		}
		return 1;//左右都不等于0 说明这个才ok 
	}
	else if (T->data != t->data)
		return 0;
}
//这个compare写的比较好哦 
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
		
		//这里想办法来保证我的这个按照题目要求的输入输出，所以我们引入一个数组1，表示yes，0表示no，最后再多输入一个0； 
		for (i = 0; i < n; i++) {
			char a[30];
			gets(a);
			for (j = 0; j < strlen(a); j++) {
				A[j] = a[j] - '0';
			}
			BiTree t;
			CreateBST(t, A, strlen(a));
			if (compare(T, t) == 1) {//两个相同 
				b[k] = 1;
				k++;
			}
			else {
				b[k] = 0;
				k++;
			}
		}//新建的一个变量在循环一次后会刷新吗？ 
		//int nothing;
		//scanf("%d", &nothing);//这个题目有点离谱，既然就已经有了n为什么要0呢？ 
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

