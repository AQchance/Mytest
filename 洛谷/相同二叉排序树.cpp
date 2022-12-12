#include <bits/stdc++.h>

using namespace std;

typedef struct BiTreeNode {
	char c;
	struct BiTreeNode* left;
	struct BiTreeNode* right;
}*Tree,TreeNode;

void BuildBiTree(Tree& t,string s,int x) {
	if (x == s.length()) return;
	if (t == 0) {
		t = new TreeNode;
		t->left = 0;
		t->right = 0;
		t->c = s[x];
		x++;
	}
	else {
		if (t->c < s[x]) BuildBiTree(t, s, x);
		else BuildBiTree(t, s, x);

	}
}

void PreOrder(Tree t,string& s) {
	if (t != 0) {
		s += t->c;
		PreOrder(t->left,s);
		PreOrder(t->right,s);
	}
}

int main()
{
	int i, j=0, k=0, n, cnt = 0, a[1000] = { 0 };
	while (1) {
		cin >> n;
		if (n == 0) break;
		else {
			string s[21], s1;
			Tree t1 = 0;
			cin >> s[0];
			BuildBiTree(t1, s[0], k);
			PreOrder(t1, s1);
			cout << "以下" << s1 << endl;
			for (i = 1; i <= n; i++) {
				cin >> s[i];
			}
			for (i = 1; i <= n;i++) {
				Tree t = 0;
				k = 0;
				BuildBiTree(t, s[i],k);
				string s3;
				PreOrder(t, s3);
				cout << "以下" << s3 << endl;
				if (s1 == s3) a[cnt] = 1;
				cnt++;
			}
		}
	}
	for (i = 0; i < cnt; i++) {
		if (a[i] == 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}