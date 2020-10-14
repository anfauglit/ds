#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ds.h"

Queue* init_queue()
{
	Queue* qp;
	qp = malloc(sizeof(Queue));
	qp->first = NULL;
	qp->last = NULL;
	qp->size = 0;

	return qp;
}

static Node* const_node(int n)
{
	Node* np;
	np = malloc(sizeof(Node));

	np->data = n;
	np->next = NULL;

	return np;
}

static void free_nodes(Node* np)
{
	if (np != NULL)
	{
		free_nodes(np->next);
		free(np);
	}
}

void free_queue(Queue* qp)
{
	free_nodes(qp->first);
	free(qp);
}

int peek(Queue* qp)
{
	if (qp->first != NULL)
		return qp->first->data;
}

void enqueue(Queue* qp, int d)
{
	Node* np;
	np = const_node(d);

	if (qp->first != NULL)
		qp->last->next = np;
	else 
		qp->first = np;

	qp->last = np;
	qp->size += 1;
}	

int dequeue(Queue* qp)
{
	Node* np;
	np = qp->first;

	int d = np->data;
	qp->first = np->next;
	qp->size -= 1;
	free(np);

	return d;
}

void print_queue(Queue* qp)
{
	Node* np;
	np = qp->first;

	while (np != NULL)
	{
		printf("%i ", np->data);
		np = np->next;
	}
}
