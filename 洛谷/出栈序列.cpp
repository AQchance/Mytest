#include<bits/stdc++.h>

using namespace std;

typedef struct Node {
	int value;
	struct Node* next;
}*LinkList,LinkNode;

void Push(LinkList &L,int x) {
	LinkNode* p = new LinkNode;
	p->next = L;
	L = p;
	L->value = x;
}

void Pop(LinkList& L) {
	LinkNode* r=L;
	L = L->next;
	free(r);
}

int Top(LinkList L) {
	return L->value;
}

int main()
{
	int n, i, j, k, a[10];
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	LinkList L = new LinkNode;
	L->next = 0;
	for (i = 0, j = 0; i < n; i++) {
		Push(L, i + 1);
		while (L->next!= 0 && a[j] == Top(L)) {
			j++;
			Pop(L);
		}
	}
	if (L->next==0) cout << "yes";
	else cout << "no";
	return 0;
}
