/*
**�ó���ʵ����һ����ջ���߱��Ļ������ܣ���ջ����ջ������ջ����ջ��Ԫ�ظ����Լ����ջ�Ƿ�Ϊ�յĲ�����
**�������ÿ�β����󣬶��������ջ�ڵ�Ԫ��
**�ó����ʵ�������ں�����ʹ�ã�����ջ�����ֲ����ú�����ʾ������ͨ�����ú�������ɳ�ջ����ջ�Ȳ���
**ջ��ģ��ģ�����������Ϊ����ջ�������Ͻ磬��ʹ��ǰ�����޶�����Ĵ�С�������ʵ������������������
**����ջ���ŵ����ڣ�ʹ�õ�ģ���Ǹ��������е�һ�־���ģ�ͣ�����⣬�������ٶȽ�����ջ��
**��������ķ�ʽ���ŵ��ǿ�����ÿ����Ҫ�洢һ���µ�Ԫ��ʱ�����ÿ�����������һ����Խ������Ĳ�������
**
*/
#include<stdio.h>
#include<stdlib.h>
/*
**������������Ҫ�Ľṹ���Լ���Ա����
**value��ʾ����������ջ��Ԫ�أ�*nextΪָ�����
*/
typedef struct node {
	int value;
	struct node* next;
}Node;
//����push����ģ����ջ����
Node* push(Node* head, int value, Node* name) {
	name = (Node*)malloc(sizeof(Node));
	name->value = value;
	name->next = head;
	return name;
}
//����top����ģ�ⷵ��ջ������
int top(Node* head) {
	return head->value;
}
//����pop����ģ���ջ����
Node* pop(Node* head) {
	head = head->next;
	return head;
}
//empty�������ڼ���ջ�Ƿ�Ϊ��
int empty(Node* head) {
	if (head == 0) return 0;
	else return 1;
}
//size�������ڼ���ջ��Ԫ�صĸ���
int size(Node* head) {
	Node* p;
	int count = 0;
	for (p = head; p != 0; p = p->next) {
		count++;
	}
	return count;
}
int main()
{
	printf("���ڶ�ջ������Խ������²�����������������\n");
	printf("��ջ������1\n");
	printf("��ջ������2\n");
	printf("����ջ��Ԫ�أ�3\n");
	printf("���ջ�Ƿ�Ϊ�գ�4\n");
	printf("����ջ��Ԫ�ظ�����5\n");
	printf("��0��������\n");
	//decision���������ж��û��Ĳ���ѡ��value������ʾջ��Ԫ��
	int decision, value;
	Node* head = 0;
	Node* name = (Node*)malloc(sizeof(Node));
	while (1) {
		scanf("%d", &decision);
		if (decision == 0) {
			//ʹ��returnֱ�ӽ�������
			printf("�������˳�\n");
			return decision;
		}
		else if (decision == 1) {
			scanf("%d", &value);
			head = push(head, value, name);
		}
		else if (decision == 2) {
			if (empty(head) == 0) printf("ջΪ�գ����ɽ��г�ջ����\n");
			else {
				head = pop(head);
			}
		}
		else if (decision == 3) {
			if (empty(head) == 0) printf("ջΪ�գ����ɽ��з���ջ������\n");
			else printf("%d\n", top(head));
		}
		else if (decision == 4) {
			if (empty(head) == 0) printf("ջΪ��\n");
			else printf("ջ��Ϊ��\n");
		}
		else if (decision == 5) {
			printf("ջ��Ԫ�صĸ���Ϊ%d��\n", size(head));
		}
		else {
			printf("���벻����Ҫ��\n");
			continue;
		}
		//ÿ�����һ�β������ջ�Ƿ�Ϊ��
		if (empty(head) == 0) printf("ջΪ�գ�ջ����Ԫ��\n");
		else {
			printf("ջ��Ԫ��Ϊ��");
			for (Node* p = head; p != 0; p = p->next) {
				printf("%d ", p->value);
			}
		}
		printf("�밴������������\n");
	}
	return 0;
}