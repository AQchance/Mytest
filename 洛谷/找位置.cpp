#include <bits/stdc++.h>

using namespace std;

typedef struct BiTreeNode {
	int index[100] = { 0 };
	int cnt = 1;
	char c;
	struct BiTreeNode* left, * right;
}*Tree,TreeNode;

void CreateBiTree(Tree& t, char c,int x) {
	if (t == 0) {
		t = new TreeNode;
		t->left = 0;
		t->right = 0;
		t->c = c;
		t->index[0] = x;
	}
	else {
		if (c < t->c) CreateBiTree(t->left, c, x);
		else if (c > t->c) CreateBiTree(t->right, c, x);
		else {
			t->index[t->cnt] = x;
			t->cnt += 1;
			return;
		}
	}
}

void Out(Tree t,char c) {
	if (t!=0) {
		if (t->c == c) {
			if (t->cnt > 1) {
				for (int i = 0; i < t->cnt; i++) {
					cout << t->c << ":" << t->index[i];
					if (i != t->cnt - 1) cout << ",";
					else cout << endl;
				}
			}
		}
		Out(t->left, c);
		Out(t->right, c);
	}
}

int main()
{
	int i;
	string s;
	cin >> s;
	Tree t = 0;
	set<char> Sets;
	for (int i = 0; i < s.length(); i++) {
		CreateBiTree(t, s[i], i);
	}
	for (i = 0; i < s.length(); i++) {
		if (Sets.count(s[i])==0) {
			Sets.insert(s[i]);
			Out(t, s[i]);
		}
	}
	return 0;
}
