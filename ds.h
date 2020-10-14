typedef struct node 
{
	int data;
	struct node* next;
} Node;

typedef struct queue
{
	Node* first;
	Node* last;
	unsigned int size;
} Queue;

Queue* init_queue();

void free_queue(Queue* qp);

int peek(Queue* qp);

void enqueue(Queue* qp, int d);

void print_queue(Queue* qp);

int dequeue(Queue* qp);
