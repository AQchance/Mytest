#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
	int index;
	int coefficient;
	struct Node* next;
}LinkList, LinkNode;

//在temp之后插入一个结点
void Insert_in_Tail(LinkList*& L, LinkNode* temp, LinkNode* q) {
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkList));
	p->index = q->index;
	p->coefficient = q->coefficient;
	p->next = temp->next;
	temp->next = p;
}

//删除temp之后的结点
void Delete_in_Tail(LinkList*& L, LinkList* temp) {
	LinkNode* r;
	r = temp->next;
	if (r == NULL) return;
	temp->next = r->next;
	free(r);
}

int main() {
	int m, n, t, i, j, k, l;
	cin >> n >> m >> t;

	//定义两个链表
	LinkList* La = (LinkList*)malloc(sizeof(LinkNode)),
		* Lb = (LinkList*)malloc(sizeof(LinkNode));

	//初始化两个链表的表头
	La->next = 0;
	LinkNode* tempa = La;
	Lb->next = 0;
	LinkNode* tempb = Lb;

	//使用循环对两个链表进行输入处理
	i = n; j = m;
	while (i > 0) {
		cin >> k >> l;
		if (k == 0) {
			i--;
			continue;
		}
		LinkList* p = (LinkList*)malloc(sizeof(LinkNode));
		p->index = l;
		p->coefficient = k;
		Insert_in_Tail(La, tempa, p);
		tempa = tempa->next;
		i--;
	}
	while (j > 0) {
		cin >> k >> l;
		if (k == 0) {
			j--;
			continue;
		}
		LinkList* p = (LinkList*)malloc(sizeof(LinkNode));
		p->index = l;
		p->coefficient = k;
		Insert_in_Tail(Lb, tempb, p);
		tempb = tempb->next;
		j--;
	}

	//t=0代表加法部分
	if (t == 0) {
		LinkList* tempa, * tempb;
		for (tempa = La, tempb = Lb->next; tempb != 0;) {
			if (tempa->next == 0) {
				Insert_in_Tail(La, tempa, tempb);
				tempb = tempb->next;
				tempa = tempa->next;
			}
			else {
				if (tempa->next->index == tempb->index) {
					tempa->next->coefficient += tempb->coefficient;
					if (tempa->next->coefficient == 0) {
						Delete_in_Tail(La, tempa);
						tempb = tempb->next;
					}
					else {//tempa保持原来所指不改变
						tempb = tempb->next;
					}
				}
				else if (tempa->next->index < tempb->index) {
					tempa = tempa->next;
				}
				else if (tempa->next->index > tempb->index) {
					Insert_in_Tail(La, tempa, tempb);
					tempa = tempa->next;
					tempb = tempb->next;
				}
			}
		}
		for (tempb = Lb->next; tempb != 0; tempb = tempb->next) {
			free(Lb);
			Lb = tempb;
		}
		if (La->next == 0) {
			cout << "0";
			return 0;
		}
		for (tempa = La->next; tempa != 0; tempa = tempa->next) {
			if (tempa == La->next) {
				if (tempa->index == 0) {
					cout << tempa->coefficient;
				}
				else if (tempa->index != 1) {
					if (tempa->coefficient > 0 && tempa->coefficient != 1) {
						cout << tempa->coefficient << "x^" << tempa->index;
					}
					else if (tempa->coefficient == 1) {
						cout << "x^" << tempa->index;
					}
					else if (tempa->coefficient < 0 && tempa->coefficient != -1) {
						cout << tempa->coefficient << "x^" << tempa->index;
					}
					else if (tempa->coefficient == -1) {
						cout << "-x^" << tempa->index;
					}
				}
				else if (tempa->index == 1) {
					if (tempa->coefficient > 0 && tempa->coefficient != 1) {
						cout << tempa->coefficient << "x";
					}
					else if (tempa->coefficient == 1) {
						cout << "x";
					}
					else if (tempa->coefficient < 0 && tempa->coefficient != -1) {
						cout << tempa->coefficient << "x";
					}
					else if (tempa->coefficient == -1) {
						cout << "-x";
					}
				}
			}

			else {
				if (tempa->index == 0) {
					if (tempa->coefficient > 0) cout << "+";
					cout << tempa->coefficient;
				}
				else if (tempa->index != 1) {
					if (tempa->coefficient > 0 && tempa->coefficient != 1) {
						cout << "+" << tempa->coefficient << "x^" << tempa->index;
					}
					else if (tempa->coefficient == 1) {
						cout << "+x^" << tempa->index;
					}
					else if (tempa->coefficient < 0 && tempa->coefficient != -1) {
						cout << tempa->coefficient << "x^" << tempa->index;
					}
					else if (tempa->coefficient == -1) {
						cout << "-x^" << tempa->index;
					}
				}
				else if (tempa->index == 1) {
					if (tempa->coefficient > 0 && tempa->coefficient != 1) {
						cout << "+" << tempa->coefficient << "x";
					}
					else if (tempa->coefficient == 1) {
						cout << "+x";
					}
					else if (tempa->coefficient < 0 && tempa->coefficient != -1) {
						cout << tempa->coefficient << "x";
					}
					else if (tempa->coefficient == -1) {
						cout << "-x";
					}
				}
			}
		}
	}

	else {
		LinkList* tempa, * tempb;
		for (tempa = La, tempb = Lb->next; tempb != 0;) {
			if (tempa->next == 0) {
				tempb->coefficient = -tempb->coefficient;
				Insert_in_Tail(La, tempa, tempb);
				tempb = tempb->next;
				tempa = tempa->next;
			}
			else {
				if (tempa->next->index == tempb->index) {
					tempa->next->coefficient -= tempb->coefficient;
					if (tempa->next->coefficient == 0) {
						Delete_in_Tail(La, tempa);
						tempb = tempb->next;
					}
					else {//tempa保持原来所指不改变
						tempb = tempb->next;
					}
				}
				else if (tempa->next->index < tempb->index) {
					tempa = tempa->next;
				}
				else if (tempa->next->index > tempb->index) {
					tempb->coefficient = 0 - tempb->coefficient;
					Insert_in_Tail(La, tempa, tempb);
					tempa = tempa->next;
					tempb = tempb->next;
				}
			}
		}
		for (tempb = Lb->next; tempb != 0; tempb = tempb->next) {
			free(Lb);
			Lb = tempb;
		}
		if (La->next == 0) {
			cout << "0";
			return 0;
		}
		for (tempa = La->next; tempa != 0; tempa = tempa->next) {
			if (tempa == La->next) {
				if (tempa->index == 0) {
					cout << tempa->coefficient;
				}
				else if (tempa->index != 1) {
					if (tempa->coefficient > 0 && tempa->coefficient != 1) {
						cout << tempa->coefficient << "x^" << tempa->index;
					}
					else if (tempa->coefficient == 1) {
						cout << "x^" << tempa->index;
					}
					else if (tempa->coefficient < 0 && tempa->coefficient != -1) {
						cout << tempa->coefficient << "x^" << tempa->index;
					}
					else if (tempa->coefficient == -1) {
						cout << "-x^" << tempa->index;
					}
				}
				else if (tempa->index == 1) {
					if (tempa->coefficient > 0 && tempa->coefficient != 1) {
						cout << tempa->coefficient << "x";
					}
					else if (tempa->coefficient == 1) {
						cout << "x";
					}
					else if (tempa->coefficient < 0 && tempa->coefficient != -1) {
						cout << tempa->coefficient << "x";
					}
					else if (tempa->coefficient == -1) {
						cout << "-x";
					}
				}
			}


			else {
				if (tempa->index == 0) {
					if (tempa->coefficient > 0) cout << "+";
					cout << tempa->coefficient;
				}
				else if (tempa->index != 1) {
					if (tempa->coefficient > 0 && tempa->coefficient != 1) {
						cout << "+" << tempa->coefficient << "x^" << tempa->index;
					}
					else if (tempa->coefficient == 1) {
						cout << "+x^" << tempa->index;
					}
					else if (tempa->coefficient < 0 && tempa->coefficient != -1) {
						cout << tempa->coefficient << "x^" << tempa->index;
					}
					else if (tempa->coefficient == -1) {
						cout << "-x^" << tempa->index;
					}
				}
				else if (tempa->index == 1) {
					if (tempa->coefficient > 0 && tempa->coefficient != 1) {
						cout << "+" << tempa->coefficient << "x";
					}
					else if (tempa->coefficient == 1) {
						cout << "+x";
					}
					else if (tempa->coefficient < 0 && tempa->coefficient != -1) {
						cout << tempa->coefficient << "x";
					}
					else if (tempa->coefficient == -1) {
						cout << "-x";
					}
				}
			}
		}
	}
}