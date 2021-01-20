#include <stdio.h>
#include <stdlib.h>
#define Array_Based_Queue
# include "queue.c"
int main()
{
    Queue q;
    QueueEntry e;
    CreateQueue(&q);
    int x;
 if (QueueEmpty(&q))
     {
          Enqueue(5,&q);
          Enqueue(6,&q);
          Enqueue(1,&q);
     }
 
    printf("The elements of the queue are: ");
         TraverseQueue(&q, &Display);
    printf("\n");
         x=QueueSize(&q);
    printf("The size of the queue: %d\n", x);
 
   if (!QueueEmpty(&q))
       {
          Dequeue(&e , &q);
       }
 
   printf("One element was removed\n");
   printf("The elements of the queue are: ");
         TraverseQueue(&q, &Display);
   printf("\n");
 
        x=QueueSize(&q);
   printf("The size of the queue: %d\n", x);
        ClearQueue(&q);
   printf("The queue now is clear\n");
        x=QueueSize(&q);
   printf("Size: %d\n", x);
 
 
    return 0;
}