#include <bits/stdc++.h>

using namespace std;

typedef struct BiTreeNode {
	char value;
	struct BiTreeNode* left;
	struct BiTreeNode* right;
}*Tree, TreeNode;

void Postorder(Tree t) {
	if (t != 0) {
		Postorder(t->left);
		Postorder(t->right);
		cout << t->value;
	}
}//后序遍历二叉树

//根据前序遍历和中序遍历建立二叉树
void BuildBiTree(Tree& t, string a, string b) {
	if (a.length() == 0) return;
	t = new TreeNode;
	t->left = 0;
	t->right = 0;
	t->value = a[0];
	string s1;
	string s2;
	string s3;
	string s4;
	int i = 0;
	while (b[i] != a[0]) {
		i++;
	}
	int j;
	for (j = 1; j <= i; j++) {
		s1 += a[j];
	}
	for (j = 0; j < i; j++) {
		s2 += b[j];
	}
	for (j = i + 1; j < a.length(); j++) {
		s3 += a[j];
	}
	for (j = i + 1; j < b.length(); j++) {
		s4 += b[j];
	}
	BuildBiTree(t->left, s1, s2);
	BuildBiTree(t->right, s3, s4);
}

int main()
{
	string s1, s2;
	cin >> s2 >> s1;
	Tree t;
	BuildBiTree(t, s1, s2);
	Postorder(t);
	return 0;
}
