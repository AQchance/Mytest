#include<bits/stdc++.h>

using namespace std;

typedef struct Node {
	char c;
	struct Node* next;
}*LinkList, LinkNode;

void Push(LinkList& L, char c) {
	LinkNode* p = new LinkNode;
	p->next = L;
	p->c = c;
	L = p;
}

void Pop(LinkList& L, char& e) {
	LinkNode* r = L;
	e = L->c;
	L = L->next;
	free(r);
}

int main()
{
	string s;
	int i, j;
	char c;
	getline(cin, s);
	LinkList L = new LinkNode;
	L->next = 0;
	for (i = 0; i < s.length(); i++) {
		if (s[i] == '{' || s[i] == '[' || s[i] == '(') Push(L, s[i]);
		else if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
			if (L->next == 0) {
				cout << "wrong";
				return 0;
			}
			else {
				Pop(L, c);
				if (c == '(' && s[i] == ')' || c == '[' && s[i] == ']' || c == '{' && s[i] == '}') continue;
				else {
					cout << "wrong";
					return 0;
				}
			}
		}
	}
	if (L->next == 0) cout << "right";
	else cout << "wrong";
	return 0;
}