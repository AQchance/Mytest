#include <bits/stdc++.h>

using namespace std;

typedef struct BiTreeNode {
	int value;
	struct BiTreeNode* left;
	struct BiTreeNode* right;
}*Tree,TreeNode;

void BuildBiTree(Tree &t, int a[], int b[], int length) {
	if (length == 0) return;
	t = new TreeNode;
	t->left = 0;
	t->right = 0;
	t->value = a[0];
	int i, j, k;
	for (j = 0; b[j] != a[0]; j++){}
	set<int> s1;
	set<int> s2;
	int a1[1000] = { 0 }, b1[1000] = { 0 }, a2[1000] = { 0 }, b2[1000] = { 0 };
	for (i = 0; i < j; i++) {
		b1[i] = b[i];
		s1.insert(b[i]);
	}
	for (k=0,i = j + 1; i < length; i++,k++) {
		b2[k] = b[i];
		s2.insert(b[i]);
	}
	for (k = 0, i = 1; k < j; i++) {
		if (s1.count(a[i]) == 1) { 
			a1[k] = a[i];
			k++;
		}
	}
	for (k = 0, i = 1; k < length - j-1; i++) {
		if (s2.count(a[i]) == 1) {
			a2[k] = a[i];
			k++;
		}
	}
	BuildBiTree(t->left, a1, b1, j);
	BuildBiTree(t->right, a2, b2, length - j - 1);
}

void Postorder(Tree t) {
	if (t != 0) {
		Postorder(t->left);
		Postorder(t->right);
		cout << t->value << " ";
	}
}//后序遍历二叉树

void Preorder(Tree t) {
	if (t != 0) {
		cout << t->value << " ";
		Preorder(t->left);
		Preorder(t->right);
	}
}//先序遍历二叉树


void Leaf(Tree t) {
	if (t != 0) {
		if (t->left == 0 && t->right == 0) {
			cout << t->value << " ";
		}
		Leaf(t->left);
		Leaf(t->right);
	}
	else return;
}
//后序遍历二叉树

int main()
{
	int n, a[1024] = { 0 }, b[1024] = { 0 };
	Tree t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	BuildBiTree(t, a, b, n);
	Leaf(t);
	cout << endl;
	Preorder(t);
	cout << endl;
	Postorder(t);
	cout << endl;
	return 0;
}