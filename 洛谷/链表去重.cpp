#include<bits/stdc++.h>

using namespace std;

typedef struct Node {
	string address;
	int num;
	string tail;
	struct Node* next;
}LinkNode, * LinkList;

struct Number {
	string address;
	int key;
	string next;
};

int main()
{
	struct Number number[101];
	struct Number t;
	int i, k, n;
	string headaddress;
	string j;
	cin >> headaddress;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> number[i].address >> number[i].key >> number[i].next;
	}
	for (i = 0, j = headaddress; i < n - 1; i++) {
		for (k = 0; k < n; k++) {
			if (number[k].address == j) {
				j = number[k].next;
				t = number[k]; number[k] = number[i]; number[i] = t;
				break;
			}
			else continue;
		}
	}
	LinkList L = new LinkNode;
	LinkNode* temp = L, * p = 0;
	for (i = 0; i < n; i++) {

		LinkNode* q = new LinkNode;
		q->num = number[i].key;
		q->address = number[i].address;
		q->tail = number[i].next;
		temp->next = q;
		temp = q;
		temp->next = 0;
	}
	for (temp = L->next; temp != 0 && temp->next != 0; temp = temp->next) {
		for (p = temp; p != 0 && p->next != 0; ) {
			if (p->next->num == temp->num || p->next->num == -temp->num) {
				LinkNode* r;
				r = p->next;
				p->next = r->next;
				p->tail = r->tail;
				free(r);
			}
			else {
				p = p->next;
			}
		}
	}
	i = 0;
	for (temp = L->next; temp != 0; temp = temp->next) {
		i++;
	}
	cout << i << endl;
	for (temp = L->next; temp != 0; temp = temp->next) {
		cout << temp->address << " " << temp->num << " " << temp->tail << endl;
	}
	return 0;
}