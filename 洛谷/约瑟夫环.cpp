#include<bits/stdc++.h>

using namespace std;

typedef struct Link {
	int num;
	int key;
	struct Link* next;
}LinkList;
void DelNode(LinkList*& L, int& e,int& f, int x) {
	int i;
	LinkList* p;
	for (int i = 1; i < x - 1; i++, L = L->next) {}
	p = L->next;
	e = p->num;
	f = p->key;
	L->next = p->next;
	L = p->next;
	free(p);
}
int main() 
{	
	LinkList *L=NULL, *End=NULL;
	int n, m, i, j;
	cin >> n;
	cin >> m;
	int ListLen = n;

	//下面分配内存空间并创造结点
	for (i = 0; i < n; i++) {
		if (i == 0) {
			L = End = (LinkList*)malloc(sizeof(LinkList));
			cin >> j;
			End->next = L;
			End->key = j;
			End->num = i + 1;
		}
		else {
			LinkList* S = (LinkList*)malloc(sizeof(LinkList));
			cin >> j;
			S->num = i+1;
			S->key = j;
			End->next = S;
			End = S;
			End->next = L;
		}
	}
	for (i = 0; i < n; i++,ListLen--) {
		if (ListLen == 1) {
			cout << L->num << " ";
			m = L->key;
			free(L);
		}
		else {
			int e, f, x;
			x = m % ListLen;
			if (x == 0) x = ListLen;
			if (x == 1) {
				cout << L->num << " ";
				m = L->key;
				LinkList *q,* p = NULL;
				for (p = L; p->next != L; p = p->next) {}
				p->next = L->next;
				q = L;
				L = L->next;
				free(q);
			}
			else {
				DelNode(L, e,f, x);
				cout << e << " ";
				m = f;
			}
		}
	}
	return 0;
}