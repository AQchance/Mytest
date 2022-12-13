#include<bits/stdc++.h>
using namespace std;
typedef struct List {
	int value;
	struct List* next;
}Node;
Node* head = NULL;
Node* temp = head;


bool Empty() {
	return temp == NULL;
}


void Push(int value) {
	Node* aList = (Node*)malloc(sizeof(Node));
	aList->value = value;
	aList->next = temp;
	temp = aList;
}


void Pop() {
	if (!Empty()) {
		temp = temp->next;
	}
	else {
		printf("ջ����Ԫ��");
	}
}


void ShowtheList() {
	cout << "���е�ʣ��Ԫ��Ϊ��" << endl;
	for(Node* p=temp;p!=head;p=p->next){
		cout << p->value << " ";
	}
	cout << endl;
}


int main()
{
	int n;
	while (1) {
		cout << "������Ҫ���еĲ���\n1:Push����\n2:Pop����\n3:�˳�����" << endl;
		scanf_s("%d", &n);
		if (n == 1) {
			cout << "��������ջ����" << endl;
			int value;
			cin >> value;
			Push(value);
			cout << "��ǰջ��Ԫ��Ϊ��" << endl;
			ShowtheList();
		}
		else if (n == 2) {
			Pop();
			cout << "��ǰջ��Ԫ��Ϊ��" << endl;
			ShowtheList();
		}
		if (n == 3) {
			break;
		}
	}
	return 0;
}