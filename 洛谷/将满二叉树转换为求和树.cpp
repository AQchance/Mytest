#include <bits/stdc++.h>

using namespace std;

typedef struct BiTreeNode {
	int value;
	struct BiTreeNode* left;
	struct BiTreeNode* right;
}*Tree, TreeNode;

void Midorder(Tree t) {
	if (t != 0) {
		Midorder(t->left);
		cout << t->value << " ";
		Midorder(t->right);
	}
}//中序遍历二叉树

//根据前序遍历和中序遍历建立二叉树
void BuildBiTree(Tree& t, int a[], int b[],int length) {
	if (length == 0) return;
	t = new TreeNode;
	t->left = 0;
	t->right = 0;
	t->value = a[0];
	int a1[1000] = { 0 }, b1[1000] = { 0 }, a2[1000] = { 0 }, b2[1000] = { 0 };
	int i = 0;
	while (b[i] != a[0]) {
		i++;
	}
	int j, k;
	for (k=0,j = 1; j <= i; j++,k++) {
		a1[k] = a[j];
	}
	for (k=0,j = 0; j < i; j++,k++) {
		b1[k] = b[j];
	}
	for (j = i + 1,k=0; j < length; j++,k++) {
		a2[k] = a[j];
	}
	for (k=0,j = i + 1; j < length; j++,k++) {
		b2[k] = b[j];
	}
	BuildBiTree(t->left, a1, b1,i);
	BuildBiTree(t->right, a2, b2,length-i-1);
}

int BuildAddBiTree(Tree& t) {
	if (t == 0) return 0;
	else {
		if (t->left == 0) t->value= 0;
		else { 
			t->value = t->left->value + t->right->value + BuildAddBiTree(t->left) + BuildAddBiTree(t->right);
		}
		return t->value;
	}
}

int main()
{
	int i, j, n, a[1024] = { 0 }, b[1024] = { 0 };
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (i = 0; i < n; i++) {
		cin >> b[i];
	}
	Tree t;
	BuildBiTree(t, a, b, n);
	BuildAddBiTree(t);
	Midorder(t);
	return 0;
}
