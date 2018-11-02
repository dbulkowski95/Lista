#ifndef LIST_H_
#define LIST_H_

typedef struct node
{
	struct node *nextNode;
	int value;
}node;

typedef struct
{
	node *head;
}list;

int push_back(list *list_p, int data);
int pop_front(list *pop_list_p);
int pop_back(list *pop_list_p);
list *init(void);
int clear(list *list_p);
int print(const list *list_p);

#endif /* LIST_H_ */
