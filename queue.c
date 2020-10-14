#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ds.h"

int main (void)
{
	Queue* qp;

	// queue initialization
	qp = init_queue();

	for (int i = 0; i < 5; ++i)
		enqueue(qp, i);
	
	//printing queue to stdout
	print_queue(qp);
	
	printf("\n");

	printf("%i\n", dequeue(qp));
	printf("%i\n", dequeue(qp));
	
	print_queue(qp);

	// free memory occupied by queue
	free_queue(qp);

	return 0;
}

