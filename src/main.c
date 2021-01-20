#include <stdio.h>
#include <stdlib.h>
#define Array_Based_Queue
# include "queue.c"
int main()
{
        Queue q;
	CreateQueue(&q);
	Enqueue(5, &q);
	Enqueue(7, &q);
	Enqueue(8, &q);
	printf("%d", QueueSize(&q));
	return 0;
}
