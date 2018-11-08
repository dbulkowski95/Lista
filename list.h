#ifndef LIST_H_
#define LIST_H_

typedef struct node
{
	struct node *nextNode;
	int value;
}nodeS;

typedef struct list
{
	nodeS *head;
}listS;

int push_back(listS *list_p, int data);
int pop_front(listS *pop_list_p, int *returnValue);
int pop_back(listS *pop_list_p, int *returnValue);
listS *init(void);
int clear(listS **listToClear);
int print(const listS *list_p);

#endif /* LIST_H_ */
