#include <bits/stdc++.h>

using namespace std;

typedef struct BiTreeNode {
	int value;
	struct BiTreeNode* left;
	struct BiTreeNode* right;
}*Tree,TreeNode;

void BuildBiTree(Tree& t, int a[][3],int x) {
	if (x == 0) return;
	t = new TreeNode;
	t->left = 0;
	t->right = 0;
	t->value = a[x][0];
	int i, j, k;
	if (a[x][1] != 0) {
		j = a[x][1];
	}
	else j = 0;
	if (a[x][2] != 0) {
		k = a[x][2];
	}
	else k = 0;
	BuildBiTree(t->left, a, j);
	BuildBiTree(t->right, a, k);
}

void JudgeTree(Tree t,int &e) {
	if (e == -1) return;
	if (t->left != 0) {
		if (t->left->value < t->value) {
			JudgeTree(t->left,e);
		}
		else {
			e = -1;
			return;
		}
	}
	if (t->right != 0) {
		if (t->right->value > t->value) {
			JudgeTree(t->right,e);
		}
		else {
			e = -1;
			return;
		}
	}
}

int main()
{
	int a[100001][3] = { 0 };
	int i, j, n, k, e = 1;
	Tree t;
	cin >> n >> k;
	for (i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	BuildBiTree(t, a, k);
	JudgeTree(t,e);
	if (e == -1) cout << "false";
	else cout << "true";
	return 0;
}