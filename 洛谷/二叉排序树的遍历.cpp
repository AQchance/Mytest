#include <bits/stdc++.h>

using namespace std;

typedef struct BiTreeNode {
	int value;
	struct BiTreeNode* left, * right;
}*Tree, TreeNode;

void PreOrder(Tree t) {
	if (t != 0) {
		cout << t->value << " ";
		PreOrder(t->left);
		PreOrder(t->right);
	}
}

void MidOrder(Tree t) {
	if (t != 0) {
		MidOrder(t->left);
		cout << t->value << " ";
		MidOrder(t->right);
	}
}

void PostOrder(Tree t) {
	if (t != 0) {
		PostOrder(t->left);
		PostOrder(t->right);
		cout << t->value << " ";
	}
}

void CreateBiTree(Tree& t, int a) {
	if (t == 0) {
		t = new TreeNode;
		t->left = 0;
		t->right = 0;
		t->value = a;
		return;
	}
	else {
		if (a > t->value) CreateBiTree(t->right, a);
		else if (a < t->value) CreateBiTree(t->left, a);
	}
}

int main()
{
	int n, a[100] = { 0 }, i;
	cin >> n;
	Tree t = 0;
	for (i = 0; i < n; i++) {
		cin >> a[i];
		CreateBiTree(t, a[i]);
	}
	PreOrder(t);
	cout << endl;
	MidOrder(t);
	cout << endl;
	PostOrder(t);
	return 0;
}