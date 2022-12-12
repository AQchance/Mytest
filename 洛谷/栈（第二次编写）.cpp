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
		printf("栈中无元素");
	}
}


void ShowtheList() {
	cout << "表中的剩余元素为：" << endl;
	for(Node* p=temp;p!=head;p=p->next){
		cout << p->value << " ";
	}
	cout << endl;
}


int main()
{
	int n;
	while (1) {
		cout << "请输入要进行的操作\n1:Push操作\n2:Pop操作\n3:退出程序" << endl;
		scanf_s("%d", &n);
		if (n == 1) {
			cout << "请输入入栈内容" << endl;
			int value;
			cin >> value;
			Push(value);
			cout << "当前栈中元素为：" << endl;
			ShowtheList();
		}
		else if (n == 2) {
			Pop();
			cout << "当前栈中元素为：" << endl;
			ShowtheList();
		}
		if (n == 3) {
			break;
		}
	}
	return 0;
}