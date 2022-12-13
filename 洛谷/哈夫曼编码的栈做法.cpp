#include<bits/stdc++.h>

using namespace std;

typedef struct Node {
	int value;
	struct Node* next;
}*LinkList,LinkNode;

void DelHeadNode(LinkList& L) {
	LinkNode* r;
	r = L->next;
	L->next = r->next;
	free(r);
}

void InsertValue(int x,LinkList& L) {
	LinkNode* temp;
	for (temp = L; temp->next != 0; temp = temp->next) {
		if (temp->next->value < x) continue;
		else {
			LinkNode* p = new LinkNode;
			p->value = x;
			p->next = temp->next;
			temp->next = p;
			return;
		}
	}
	LinkNode* p = new LinkNode;
	p->next = 0;
	temp->next = p;
	p->value = x;
}

int main()
{
	int i, j, k, n, a[100], sum = 0, l;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	LinkList L = new LinkNode;
	L->next = 0;
	LinkNode* temp;
	for (temp = L, i = 0; i < n; i++) {
		LinkNode* p = new LinkNode;
		p->next = 0;
		p->value = a[i];
		temp->next = p;
		temp = p;
	}
	while (L->next->next != 0) {
		j = L->next->value;
		k = L->next->next->value;
		l = j + k;
		sum += l;
		DelHeadNode(L);
		DelHeadNode(L);
		InsertValue(l, L);
	}
	cout << sum;
	return 0;
}