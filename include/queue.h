#ifdef Array_Based_Queue

# define QueueEntry int
# define MAXQUEUE 100
typedef struct queue {
    int front;
    int rear;
    int size;
    QueueEntry entry[MAXQUEUE];
 
}Queue;
 
void CreateQueue(Queue *pq);
 
void Enqueue(QueueEntry e, Queue* pq);
 
void Dequeue(QueueEntry *pe, Queue* pq);
 
int QueueEmpty(Queue* pq);
 
int QueueFull(Queue* pq);
 
int QueueSize(Queue* pq);
 
void ClearQueue(Queue* pq);
 
void TraverseQueue(Queue * pq, void(*pf)(QueueEntry));
 
void Display (QueueEntry e);


#else
# define QueueEntry int
# define MAXQUEUE 100
 
typedef struct queuenode {
    QueueEntry entry;
    struct queuenode *next;
 
}QueueNode;
 
typedef struct queue {
    QueueNode *front;
    QueueNode *rear;
    int size; //old trick
 
}Queue;
 
void CreateQueue(Queue *pq);
 
int Enqueue(QueueEntry e, Queue* pq);
 
void Dequeue(QueueEntry *pe, Queue* pq);
 
int QueueEmpty(Queue* pq);
 
int QueueFull(Queue* pq);
 
int QueueSize(Queue* pq);
 
void ClearQueue(Queue* pq);
 
void TraverseQueue(Queue * pq, void(*pf)(QueueEntry));
 
void Display (QueueEntry e);
#endif
