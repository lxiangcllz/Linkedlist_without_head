//无空的头结点的链表的头文件

#ifndef _LIST_NO_HEAD_
#define _LIST_NO_HEAD_

struct node {
	int data;
	struct node *next;
};

//创建无头链表
void make_list(struct node **phead);

//创建一个新节点
struct node *make_node(int data);

//释放一个节点
void free_node(struct node *free_node);

//从链表尾部插入一个节点
void insert_to_tail(struct node **phead, struct node *pnode);

//从链表头部插入一个节点
void insert_to_head(struct node **phead, struct node *pnode);

//从链表中指定一个节点(非头结点)前插入一个节点
void insert_before_node(struct node *head, struct node *p, int data);

//从链表中指定一个节点（非尾节点）后插入一个节点
void insert_after_node(struct node *p, int data);

//查找一个节点
struct node *search_node(struct node *head, int data);

//删除一个节点
void delete_node(struct node **phead, struct node *pnode);

//打印输出链表所有节点值
void print_list_no_head(struct node *head);

//释放一个链表
void free_list_no_head(struct node **phead);



#endif
