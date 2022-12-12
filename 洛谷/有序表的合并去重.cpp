#include<bits/stdc++.h>

using namespace std;

typedef struct Node {
	int value;
	struct Node* next;
}*LinkList, LinkNode;

int main()
{
	LinkList L1 = new LinkNode;
	LinkList L2 = new LinkNode;
	L1->next = L2->next = 0;
	int n, i, j, m;
	LinkNode* temp1, * temp2;
	cin >> n >> m;
	for (temp1 = L1, i = 0; i < n; i++) {
		cin >> j;
		LinkNode* p = new LinkNode;
		p->next = 0;
		p->value = j;
		temp1->next = p;
		temp1 = p;
	}
	for (temp2 = L2, i = 0; i < m; i++) {
		cin >> j;
		LinkNode* p = new LinkNode;
		p->next = 0;
		p->value = j;
		temp2->next = p;
		temp2 = p;
	}
	temp2 = L2;
	temp1 = L1;
	while (temp2->next != 0) {
		if (temp1->next == 0) {
			LinkNode* p = new LinkNode;
			temp1->next = p;
			p->next = 0;
			p->value = temp2->next->value;
			temp1 = p;
			temp2 = temp2->next;
		}
		else {
			if (temp1->next->value > temp2->next->value) {
				LinkNode* p = new LinkNode;
				p->next = temp1->next;
				temp1->next = p;
				p->value = temp2->next->value;
				temp1 = p;
				temp2 = temp2->next;
			}
			else if (temp1->next->value == temp2->next->value) {
				temp2 = temp2->next;
			}
			else if (temp1->next->value < temp2->next->value) {
				temp1 = temp1->next;
			}
		}
	}
	for (temp2 = L2; temp2->next != 0;) {
		LinkNode* r = new LinkNode;
		r = temp2->next;
		temp2->next = r->next;
		free(r);
	}
	for (temp1 = L1->next; temp1 != 0; temp1 = temp1->next) {
		cout << temp1->value << " ";
	}
	return 0;
}