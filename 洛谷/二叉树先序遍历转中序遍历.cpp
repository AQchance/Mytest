#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
	char c;
	struct Node* next;
}*LinkList,LinkNode;

void Push(LinkList& L, char c) {
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	p->next = L;
	L = p;
	p->c = c;
}

void Pop(LinkList& L, char& e) {
	LinkNode* r = L;
	e = L->c;
	L = L->next;
	free(r);
}

int main()
{
	int i, j;
	char e;
	string s;
	cin >> s;
	LinkList L = (LinkList)malloc(sizeof(LinkNode));
	L->next = 0;
	for (i = 0; i < s.length(); i++) {
		if (s[i] == '#') {
			if (L->next == 0) return 0;
			else {
				Pop(L, e);
				cout << e << " ";
			}
		}
		else {
			Push(L, s[i]);
		}
	}
	return 0;
}