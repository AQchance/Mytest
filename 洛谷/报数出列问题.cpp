#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
	int num;
	struct Node* next;
}*LinkList, LinkNode;

int main()
{
	int i, j, k, n;
	cin >> n;
	if (n <= 3) {
		for (i = 1; i <= n; i++) {
			cout << i << " ";
		}
		return 0;
	}
	else if (n == 4) {
		cout << "1 3 4";
		return 0;
	}
	else if (n == 5 || n == 6) {
		cout << "1 3 5";
		return 0;
	}
	else {
		LinkList L = new LinkNode;
		LinkNode* temp = L;
		for (i = 1; i <= n; i += 2) {
			LinkNode* p = new LinkNode;
			p->num = i;
			temp->next = p;
			temp = p;
			temp->next = 0;
		}
		while (L->next->next->next->next != 0) {
			for (j = 3, i = 1, temp = L; temp->next != 0; i++) {
				if (i % j == 0) {
					LinkNode* r;
					r = temp->next;
					temp->next = r->next;
					free(r);
				}
				else {
					temp = temp->next;
				}
			}
			if (L->next->next->next == 0 || L->next->next->next->next == 0) goto out;
			for (j = 2, i = 1, temp = L; temp->next != 0; i++) {
				if (i % j == 0) {
					LinkNode* r;
					r = temp->next;
					temp->next = r->next;
					free(r);
				}
				else {
					temp = temp->next;
				}
			}
			if (L->next->next->next == 0 || L->next->next->next->next == 0) goto out;
		}
	out:
		for (temp = L->next; temp != 0; temp = temp->next) {
			cout << temp->num << " ";
		}
	}
	return 0;
}