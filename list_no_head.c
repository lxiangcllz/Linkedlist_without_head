//无空节点的链表的接口函数的定义文件

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list_no_head.h"

//创建无头链表
void make_list(struct node **phead) {
	if (!phead) {
		fprintf(stderr, "Invalid argument in make_list\n");
		return;
	}
	*phead = NULL;
	printf("A list without head is made\n");
	return;
}

//创建一个新节点
struct node *make_node(int data) {
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	if (!new_node) {
		fprintf(stderr, "make_node malloc error\n");
		return NULL;
	}
	memset(new_node, 0, sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}

//释放一个节点
void free_node(struct node **free_node) { 
	if (!free_node) {
		fprintf(stderr, "Invalid argument in free_node\n");
		return;
	}
	struct node *temp = *free_node;
	printf("Data %d is freed\n", temp->data);
	free(temp);
	*free_node = NULL;
	return;
}
//void free_node(struct node *node) {
//	if (!node) {
//		free(node);
//	}
//}

//从链表尾部插入一个节点
void insert_to_tail(struct node **phead, struct node *pnode) {
	if (!phead && !pnode) {
		fprintf(stderr, "Invalid arguments in insert_to_tail\n");
		return;
	}
	struct node *head = *phead;
	struct node *last_node = NULL; //链表尾节点
	if (head == NULL) { //原链表为空
		head = pnode;
	}
	else {
		for (last_node = head; last_node->next != NULL; last_node = last_node->next); //找尾节点
		last_node->next = pnode;
	}
	*phead = head;
	printf("Insert to tail succeeded\n");
	return;
}

//从链表头部插入一个节点
void insert_to_head(struct node **phead, struct node *pnode) {
	if (!phead && !pnode) {
		fprintf(stderr, "Invalid srguments in insert_to_head\n");
		return;
	}
	struct node *head = *phead;
	if (head == NULL) {
		head = pnode;
	}
	else {
		pnode->next = head;
		head = pnode;
	}
	*phead = head;
	printf("Insert to head succeeded\n");
	return;
}

//从链表中指定一个节点(非头结点)前插入一个节点
void insert_before_node(struct node *head, struct node *p, int data) {
	if (!head && !p) {
		fprintf(stderr, "Invalid arguments in insert_to_node\n");
		return;
	}
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	if (!new_node) {
		fprintf(stderr, "malloc error in new_node allocation\n");
		return;
	}
	memset(new_node, 0, sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;

	struct node *temp = head;
	while (temp->next != p) {
		temp = temp->next;
	}
	new_node->next = p;
	temp->next = new_node;

	return;
}

//从链表中指定一个节点（非尾节点）后插入一个节点
void insert_after_node(struct node *p, int data) {
	if (!p) {
		fprintf(stderr, "Invalid argument in insert_after_node\n");
		return;
	}
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	if (!new_node) {
		fprintf(stderr, "malloc error in new_node allocation\n");
		return;
	}
	memset(new_node, 0, sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;

	new_node->next = p->next;
	p->next = new_node;

	return;
}

//查找一个节点
struct node *search_node(struct node *head, int data) {
	if (!head) {
		fprintf(stderr, "Invalid argument in search_node\n");
		return NULL;
	}
	/*struct node *p = NULL;
	for (p = head; p != NULL; p = p->next) {
		if (p->data == data)
			return p;
	}*/
	struct node *p = head;
	while (p != NULL) {
		if (p->data == data) {
			break;
		}
		p = p->next;
	}
	return p;
}

//删除一个节点
void delete_node(struct node **phead, struct node **pnode) {
	if (!phead && !pnode) {
		fprintf(stderr, "Invalid argument in delete_node\n");
		return;
	}
	struct node *p = *phead;
	struct node *temp_node = *pnode;
	if (p == temp_node) { //if(p->data == temp_node->data),即原链表第一个节点即为要删除的节点
		p = p->next;
		free_node(&temp_node);
		*phead = p;
		return;
	}
	while (p != NULL) {
		if (p->next == temp_node) { //if(p->next->data == pnode->data)
			p->next = temp_node->next;
			free_node(&temp_node);
			break;
		}
		p = p->next;
	}
	*phead = p;
	return;
}

//打印输出链表所有节点值
void print_list_no_head(struct node *head) {
	if (!head) {
		fprintf(stderr, "Invalid argument in print_list_no_head\n");
		return;
	}
	struct node *p = NULL;
	for (p = head; p != NULL; p = p->next) {
		printf("%d\n", p->data);
	}
	return;
}

//释放一个链表
void free_list_no_head(struct node **phead) {
	if (!phead) {
		fprintf(stderr, "Invalid argument in free_list_no_head\n");
		return;
	}
	struct node *head = *phead;
	struct node *p = NULL;
	while (head) {
		p = head;
		head = head->next;
		free_node(&p);
	}
	*phead = head;
	printf("The list is freed\n");

	return;
}


