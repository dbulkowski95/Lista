#ifndef LIST_H_
#define LIST_H_

typedef struct node
{
	struct node *nextNode;
	int value;
}node;

typedef struct list
{
	node *head;
}list;

int push_back(list *list_p, int data);
int pop_front(list *pop_list_p, int *returnValue);
int pop_back(list *pop_list_p, int *returnValue);
list *init(void);
int clear(list *list_p);
int print(const list *list_p);

#endif /* LIST_H_ */
