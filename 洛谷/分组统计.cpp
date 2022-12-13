#include <iostream>
#include<algorithm>
#include<set>

using namespace std;

int No = 0;
typedef struct BiTreeNode {
	int value;
	int tumple[10001]={ 0 };
	BiTreeNode* left, * right;
}*Tree,TreeNode;

void CreateBiTree(Tree& t, int x, int y) {
	if (t == 0) {
		t = new TreeNode;
		t->left = 0;
		t->right = 0;
		t->value = x;
		t->tumple[y]+=1;
	}
	else {
		if (x < t->value) CreateBiTree(t->left, x, y);
		else if (x > t->value) CreateBiTree(t->right, x, y);
		else {
			t->tumple[y] += 1;
		}
	}
	return;
}

void MidOrder(Tree t,int x) {
	if (t != 0) {
		MidOrder(t->left,x);
		if (No > 0) cout << ",";
		cout << t->value << "=" << t->tumple[x];
		No++;
		MidOrder(t->right, x);
	}
}

void Out(Tree t,set<int> s) {
	for (auto it = s.begin(); it != s.end(); it++) {
		No = 0;
		cout << *it << "={";
		Tree temp = t;
		MidOrder(t, *it);
		cout << "}" << endl;
	}
}

int main()
{
	int i, j, k, m, n;
	cin >> m;
	Tree t[50] = { 0 };
	set<int> s[50];
	for (k = 0; k < m; k++) {
		cin >> n;
		int a[100] = { 0 }, b[100] = { 0 };
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (i = 0; i < n; i++) {
			cin >> b[i];
			s[k].insert(b[i]);
		}
		for (i = 0; i < n; i++) {
			CreateBiTree(t[k], a[i], b[i]);
		}
	}
	for (i = 0; i < k; i++) {
		j = 0;
		Out(t[i], s[i]);
	}
	return 0;
}