/*
**该程序实现了一个堆栈所具备的基本功能（出栈、入栈、返回栈顶、栈中元素个数以及检查栈是否为空的操作）
**并且完成每次操作后，都会输出堆栈内的元素
**该程序的实现依赖于函数的使用，将堆栈的五种操作用函数表示出来，通过调用函数，完成出栈、入栈等操作
**栈的模型模拟基于链表，因为数组栈存在着上界，在使用前必须限定数组的大小，因此在实际问题中往往不适用
**数组栈的优点在于，使用的模型是各种语言中的一种经典模型，易理解，且运行速度较链表栈快
**采用链表的方式的优点是可以在每当想要存储一个新的元素时，不用考虑类似数组一样的越界现象的产生问题
**
*/
#include<stdio.h>
#include<stdlib.h>
/*
**创建链表所需要的结构体以及成员变量
**value表示整型数，即栈中元素，*next为指针变量
*/
typedef struct node {
	int value;
	struct node* next;
}Node;
//创建push函数模拟入栈操作
Node* push(Node* head, int value, Node* name) {
	name = (Node*)malloc(sizeof(Node));
	name->value = value;
	name->next = head;
	return name;
}
//创建top函数模拟返回栈顶操作
int top(Node* head) {
	return head->value;
}
//创建pop函数模拟出栈操作
Node* pop(Node* head) {
	head = head->next;
	return head;
}
//empty函数用于检验栈是否为空
int empty(Node* head) {
	if (head == 0) return 0;
	else return 1;
}
//size函数用于计算栈中元素的个数
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
	printf("关于堆栈，你可以进行以下操作（请您按键）：\n");
	printf("入栈操作：1\n");
	printf("出栈操作：2\n");
	printf("返回栈顶元素：3\n");
	printf("检查栈是否为空：4\n");
	printf("返回栈中元素个数：5\n");
	printf("按0结束操作\n");
	//decision变量用于判断用户的操作选择，value变量表示栈中元素
	int decision, value;
	Node* head = 0;
	Node* name = (Node*)malloc(sizeof(Node));
	while (1) {
		scanf("%d", &decision);
		if (decision == 0) {
			//使用return直接结束程序
			printf("程序已退出\n");
			return decision;
		}
		else if (decision == 1) {
			scanf("%d", &value);
			head = push(head, value, name);
		}
		else if (decision == 2) {
			if (empty(head) == 0) printf("栈为空，不可进行出栈操作\n");
			else {
				head = pop(head);
			}
		}
		else if (decision == 3) {
			if (empty(head) == 0) printf("栈为空，不可进行返回栈顶操作\n");
			else printf("%d\n", top(head));
		}
		else if (decision == 4) {
			if (empty(head) == 0) printf("栈为空\n");
			else printf("栈不为空\n");
		}
		else if (decision == 5) {
			printf("栈中元素的个数为%d个\n", size(head));
		}
		else {
			printf("输入不符合要求\n");
			continue;
		}
		//每次完成一次操作检查栈是否为空
		if (empty(head) == 0) printf("栈为空，栈中无元素\n");
		else {
			printf("栈中元素为：");
			for (Node* p = head; p != 0; p = p->next) {
				printf("%d ", p->value);
			}
		}
		printf("请按键继续操作：\n");
	}
	return 0;
}