#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
	struct Node* next;
	int x, y, choice;
}LinkNode, * LinkList;

bool IsEmpty(LinkList L) {
	if (L->next == 0) return 1;
	return 0;
}

void Push(LinkList& L, int x, int y, int choice) {
	LinkNode* q = (LinkNode*)malloc(sizeof(LinkNode));
	q->x = x;
	q->y = y;
	q->choice = choice;
	q->next = L;
	L = q;
}

void Pop(LinkList& L, int& x, int& y, int& e) {
	LinkNode* p = L;
	e = p->choice;
	x = p->x;
	y = p->y;
	L = L->next;
	free(p);
}

int main()
{
	int m, n, start_x, start_y, end_x, end_y, i, j, e, x, y;
	int a[100][100] = { 0 };
	LinkList L = (LinkList)malloc(sizeof(LinkNode));
	L->next = 0;
	cin >> m >> n;
	cin >> start_x >> start_y;
	cin >> end_x >> end_y;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	i = start_x - 1;
	j = start_y - 1;
	if (a[i][j] == 1) {
		cout << "no";
		return 0;
	}
	while (i != end_x - 1 || j != end_y - 1) {
		if (j == n - 1 || a[i][j + 1] == 1) {
			if (i == m - 1 || a[i + 1][j] == 1) {
				if (j == 0 || a[i][j - 1] == 1) {
					if (i == 0 || a[i - 1][j] == 1) {
						a[i][j] = 1;
						if (IsEmpty(L)) {
							cout << "no";
							return 0;
						}
						Pop(L, x, y, e);
						i = x - 1;
						j = y - 1;
					}
					else {
						Push(L, i + 1, j + 1, 4);
						a[i][j] = 1;
						i--; continue;
					}
				}
				else {
					Push(L, i + 1, j + 1, 3);
					a[i][j] = 1;
					j--; continue;
				}
			}
			else {
				Push(L, i + 1, j + 1, 2);
				a[i][j] = 1;
				i++; continue;
			}
		}
		else {
			Push(L, i + 1, j + 1, 1);
			a[i][j] = 1;
			j++; continue;
		}
	}
	if (j == n - 1) Push(L, i + 1, j + 1, 1);
	else if (i == m) Push(L, i + 1, j + 1, 2);
	else if (j == 0) Push(L, i + 1, j + 1, 3);
	else if (i == 0) Push(L, i + 1, j + 1, 4);
	LinkList M = (LinkList)malloc(sizeof(LinkNode));
	M->next = 0;
	while (!IsEmpty(L)) {
		Pop(L, x, y, e);
		Push(M, x, y, e);
	}
	Pop(M, x, y, e);
	cout << "(" << x << "," << y << "," << e << ")";
	while (!IsEmpty(M)) {
		Pop(M, x, y, e);
		cout << ",(" << x << "," << y << "," << e << ")";
	}
	return 0;
}
