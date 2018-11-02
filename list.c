#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int push_back(list *list_p, int data)
{
	if(!list_p)
	{
		printf("Uninitalized list\n");
	    return -1;
	}
	if(list_p->head == NULL){
		list_p->head = malloc(sizeof(node));
		list_p->head->value = data;
		list_p->head->nextNode = NULL;
		return 0;
	}
	node *current_node_p = list_p->head;
	while(current_node_p->nextNode != NULL){
		current_node_p = current_node_p->nextNode;
	}
	current_node_p->nextNode = malloc(sizeof(node));
	current_node_p = current_node_p->nextNode;
	current_node_p->value = data;
	current_node_p->nextNode = NULL;
	return 0;
}

int clear(list *list_p)
{
	if(!list_p)
	{
		return -1;
	}
	if(list_p->head == NULL)
	{
		printf("no list to clear\n");
		return 0;
	}
	node *temp_node_p = NULL;
	while(list_p->head != NULL)
	{
		temp_node_p = list_p->head->nextNode;
		free(list_p->head);
		list_p->head = NULL;
		list_p->head = temp_node_p;
	}
	printf("List Clear. No nodes here\n");
	return 1;
	}

int print(const list *print_p)
{
	if(!print_p)
	{
		return -1;
	}
	node *print_list_p = print_p->head;
	while(print_list_p != NULL)
	{
		printf("|H->value: %d|\n",print_list_p->value);
		printf("|H->ptr:%p|\n",print_list_p->nextNode);
		print_list_p = print_list_p->nextNode;
	}
	if(print_p->head == NULL)
	{
		printf("Empty list...\n");
		return 0;
	}
	return 1;
}

int pop_front(list *pop_list_p)
{
	if(!pop_list_p)
	{
		return -1;
	}
	if(pop_list_p->head == NULL)
	{
		printf("Empty list...\n");
		return 0;
	}
	node *temp_node_p = pop_list_p->head;
	pop_list_p->head = pop_list_p->head->nextNode;
	free(temp_node_p);
	temp_node_p = NULL;
	return 1;
}

int pop_back(list *pop_list_p)
{
	if(!pop_list_p)
	{
		return -1;
	}
	if(pop_list_p->head == NULL)
	{
		printf("Empty list...\n");
		return 0;
	}
	else if(pop_list_p->head->nextNode == NULL)
	{
		free(pop_list_p->head);
		pop_list_p->head = NULL;
		printf("Removed last element.\n");
		return 0;
	}
	else
	{
		node *curr_node_p = pop_list_p->head->nextNode;
		node *prev_node_p = pop_list_p->head;
		while(curr_node_p->nextNode != NULL)
		{
			curr_node_p = curr_node_p->nextNode;
			prev_node_p = prev_node_p->nextNode;
		}
		free(curr_node_p);
		curr_node_p = NULL;
		prev_node_p->nextNode = NULL;
		return 0;
	}
	return -1;
}

list *init(void)
{
	list *init_p = malloc(sizeof(list));
	init_p->head = NULL;
	return init_p;
}

