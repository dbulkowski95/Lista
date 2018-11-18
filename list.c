#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#define PRINT(expr) (void)printf(#expr"\n")

int push_back(listS *list_p, const int data)
{
	if (!list_p)
	{
		PRINT(Uninitalized list);
	    return -1;
	}
	if (list_p->head == NULL)
	{
		list_p->head = (nodeS*)malloc(sizeof(nodeS));
		list_p->head->value = data;
		list_p->head->nextNode = NULL;
		return 0;
	}
	nodeS *current_node_p = list_p->head;
	while (current_node_p->nextNode != NULL)
	{
		current_node_p = current_node_p->nextNode;
	}
	current_node_p->nextNode = (nodeS*)malloc(sizeof(nodeS));
	current_node_p = current_node_p->nextNode;
	current_node_p->value = data;
	current_node_p->nextNode = NULL;
	return 0;
}

int push_front(listS *list_p, const int data)
{
	if (!list_p)
	{
		PRINT(Uninitalized list);
	    return -1;
	}
	if (list_p->head == NULL)
	{
		list_p->head = (nodeS*)malloc(sizeof(nodeS));
		list_p->head->value = data;
		list_p->head->nextNode = NULL;
		return 0;
	}
	nodeS *current_node_p = list_p->head;
	list_p->head = (nodeS*)malloc(sizeof(nodeS));
	list_p->head->value = data;
	list_p->head->nextNode = current_node_p;
	return 0;
}

int clear(listS **listToClear)
{
	listS *list_p = *listToClear;
	if (!listToClear)
	{
		PRINT(Uninitalized list);
		return -1;
	}
	if (list_p->head == NULL)
	{
		PRINT(no list to clear);
		free(*listToClear);
		*listToClear = NULL;
		return 0;
	}
	nodeS *temp_node_p = NULL;
	while (list_p->head != NULL)
	{
		temp_node_p = list_p->head->nextNode;
		free(list_p->head);
		list_p->head = NULL;
		list_p->head = temp_node_p;
	}
	PRINT(List Clear. No nodes here);
	free(*listToClear);
	*listToClear = NULL;
	return 0;
	}

int print(const listS *print_p)
{
	if (!print_p)
	{
		PRINT(Uninitalized list);
		return -1;
	}
	nodeS *print_list_p = print_p->head;
	while (print_list_p != NULL)
	{
		printf("|H->value: %d|\n",print_list_p->value);
		printf("|H->ptr:%p|\n",print_list_p->nextNode);
		print_list_p = print_list_p->nextNode;
	}
	if (print_p->head == NULL)
	{
		PRINT(Empty list...);
		return 0;
	}
	return 1;
}

int pop_front(listS *pop_list_p, int *returnValue)
{
	if (!pop_list_p)
	{
		PRINT(Uninitalized list);
		return -1;
	}
	if (pop_list_p->head == NULL)
	{
		PRINT(Empty list...);
		return 0;
	}
	if (returnValue)
	{
		*returnValue = pop_list_p->head->value;
	}
	nodeS *temp_node_p = pop_list_p->head;
	pop_list_p->head = pop_list_p->head->nextNode;
	free(temp_node_p);
	temp_node_p = NULL;
	return 0;
}

int pop_back(listS *pop_list_p, int *returnValue)
{
	if (!pop_list_p)
	{
		PRINT(Uninitalized list);
		return -1;
	}
	if (pop_list_p->head == NULL)
	{
		PRINT(Empty list...);
		return 0;
	}
	else if (pop_list_p->head->nextNode == NULL)
	{
		free(pop_list_p->head);
		pop_list_p->head = NULL;
		PRINT(Removed last element.);
		return 0;
	}
	else
	{
		nodeS *prev_node_p = pop_list_p->head;
		nodeS *curr_node_p = prev_node_p->nextNode;

		while (curr_node_p->nextNode != NULL)
		{
			curr_node_p = curr_node_p->nextNode;
			prev_node_p = prev_node_p->nextNode;
		}
		if (returnValue)
		{
			*returnValue = pop_list_p->head->value;
		}
		free(curr_node_p);
		curr_node_p = NULL;
		prev_node_p->nextNode = NULL;
		return 0;
	}
	return -1;
}

listS* init(void)
{
	listS* init_p = (listS*)malloc(sizeof(listS));
	if (!init_p)
	{
		return NULL;
	}
	init_p->head = NULL;
	return init_p;
}
