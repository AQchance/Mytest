#include<bits/stdc++.h>

using namespace std;

typedef struct Node {
	int num;
	struct Node* next;
}*LinkList, LinkNode;

int main()
{
	int n, i, j;
	cin >> n;
	LinkList L1 = new LinkNode;
	L1->next = 0;
	LinkList L2 = new LinkNode;
	L2->next = 0;
	LinkNode* temp1 = L1, * temp2 = L2;
	for (i = 1; i <= n; i++) {
		cin >> j;
		if (i % 2 != 0) {
			LinkNode* p = new LinkNode;
			p->next = 0;
			temp1->next = p;
			p->num = j;
			temp1 = p;
		}
		else {
			LinkNode* p = new LinkNode;
			p->next = 0;
			temp2->next = p;
			p->num = j;
			temp2 = p;
		}
	}
	for (temp2 = L1->next; temp2 != 0; temp2 = temp2->next) {
		cout << temp2->num << " ";
	}
	for (temp2 = L2->next; temp2 != 0; temp2 = temp2->next) {
		cout << temp2->num << " ";
	}
	return 0;
}