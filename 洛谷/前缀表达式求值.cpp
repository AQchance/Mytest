#include<bits/stdc++.h>

using namespace std;

typedef struct Node {
	int x;
	struct Node* next;
}*LinkList, LinkNode;

void Push(LinkList& L, int x) {
	LinkNode* p = new LinkNode;
	p->next = L;
	p->x = x;
	L = p;
}

void Pop(LinkList& L, int& x) {
	LinkNode* r = L;
	x = L->x;
	L = L->next;
	free(r);
}

int main()
{
	int i, j, e, f, k;
	string s;
	getline(cin, s);
	LinkList L = new LinkNode;
	L->next = 0;
	for (i = s.length()-1; i >= 0; i--) {
		if (s[i] <= '9' && s[i] >= '0') {
			for (; s[i] != ' '; i--) {}
			k = i;
			i++;
			for (j=0; s[i] != ' ' && i < s.length(); i++) {
				j *= 10;
				j += s[i] - '0';
			}
			Push(L, j);
			i = k;
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
				Push(L, e - f);
			}
			else if (s[i] == '*') {
				Pop(L, e);
				Pop(L, f);
				Push(L, e * f);
			}
			else if (s[i] == '/') {
				Pop(L, e);
				Pop(L, f);
				Push(L, e / f);
			}
		}
	}
	Pop(L, e);
	cout << e;
	return 0;
}


