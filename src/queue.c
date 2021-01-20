#ifdef Array_Based_Queue
# include"../include/queue.h"
void CreateQueue(Queue *pq)
{
    pq->front= 0;
    pq->rear= -1;
    pq->size=  0;
}
 
void Enqueue(QueueEntry e, Queue* pq)
{
    pq->rear = (pq->rear +1 ) % MAXQUEUE;
    pq->entry[pq->rear] = e;
    pq->size++;
}
 
void Dequeue(QueueEntry *pe, Queue* pq)
{
    *pe = pq->entry[pq->front];
    pq->front = (pq->front + 1 ) % MAXQUEUE;
    pq->size--;
}
 
int QueueEmpty(Queue* pq)
{
    return !pq->size;
}
 
int QueueFull(Queue* pq)
{
    return (pq->size == MAXQUEUE);
}
 
int QueueSize(Queue* pq)
{
    return pq->size;
}
 
void ClearQueue(Queue* pq)
{
    pq->front= 0;
    pq->rear= -1;
    pq->size=  0;
}
 
void TraverseQueue(Queue * pq, void(*pf)(QueueEntry))
{
    int pos,s;
    for (pos=pq->front, s=0; s<pq->size; s++)
    {
        (*pf)(pq->entry[pos]);
        pos=( pos + 1)% MAXQUEUE;
    }
}
 
void Display (QueueEntry e)
{
   printf("%d " , e);
}

#else

# include "../include/queue.h"
 
void Dequeue(QueueEntry *pe, Queue* pq)
{
   QueueNode *pn= pq->front;
   *pe= pn->entry;
   pq->front= pn->next;
   free(pn);
   if(!pq->front)
    pq->rear= NULL;
   pq->size--;
}
 
int QueueEmpty(Queue* pq)
{
    return !pq->front;
}
 
int QueueFull(Queue* pq)
{
    return 0;
}
 
int QueueSize(Queue* pq)
{
    return pq->size;
}
 
void ClearQueue(Queue* pq)
{
    while(pq->front)
    {
        pq->rear= pq->front->next;
        free(pq->front);
        pq->front= pq->rear;
    }
    //Moving with two pointers
    pq->size= 0;
}
 
void TraverseQueue(Queue * pq, void(*pf)(QueueEntry))
{
 
    for (QueueNode *pn=pq->front; pn; pn=pn->next)
          (*pf)(pn->entry);
 
 
}
 
void Display (QueueEntry e)
{
   printf("%d " , e);
}
 
#endif
