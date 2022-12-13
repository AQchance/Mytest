#include<bits/stdc++.h>

using namespace std;

typedef struct Node {
	int x;
	struct Node* next;
}*LinkList,LinkNode;

void Push(LinkList& L, int x) {
	LinkNode* p = new LinkNode;
	p->next = L;
	p->x = x;
	L = p;
}

void Pop(LinkList& L,int &x) {
	LinkNode* r = L;
	x = L->x;
	L = L->next;
	free(r);
}

int main()
{
	int i, j, e, f;
	string s;
	cin >> s;
	LinkList L = new LinkNode;
	L->next = 0;
	for (i = 0; i < s.length(); i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			j = s[i] - '0';
			Push(L, j);
		}
		else {
			if (s[i] == '+') {
				Pop(L, e);
				Pop(L, f);
				Push(L, e + f);
			}
			else if (s[i] == '-') {
				Pop(L, e);
				Pop(L, f);
				Push(L, f - e);
			}
			else if (s[i] == '*') {
				Pop(L, e);
				Pop(L, f);
				Push(L, e * f);
			}
			else if (s[i]=='/') {
				Pop(L, e);
				Pop(L, f);
				Push(L, f / e);
			}
		}
	}
	Pop(L, e);
	cout << e;
	return 0;
}


