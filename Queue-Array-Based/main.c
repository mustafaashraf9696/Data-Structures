#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

#define MAXQUEUE 100 
typedef int QueueEntry;


typedef struct queue {
    int front;
    int rear;
    int Size;
    QueueEntry entry[MAXQUEUE];
}Queue;


void CreatQueue(Queue* pq) {
    pq->front = 0;
    pq->rear = -1;
    pq->Size = 0;
}

void Append(QueueEntry e, Queue* pq) {
    pq->rear = (pq->rear + 1) % MAXQUEUE;
    pq->entry[pq->rear] = e;
    pq->Size++;
}

void Serve(QueueEntry* pe, Queue* pq) {
    pe = pq->entry[pq->front];
    pq->front = (pq->front + 1) % MAXQUEUE;
    pq->Size--;
}

int QueueEmpty(Queue* pq) {
    return !(pq->Size);
}

int QueueFull(Queue* pq) {
    return (pq->Size == MAXQUEUE);
}

int QueueSize(Queue* pq) {
    return pq->Size;
}

void ClearQueue(Queue* pq) {
    pq->front = 0;
    pq->rear = -1;
    pq->Size = 0;
    }

int FrontQueue(Queue* pq) {
    return (pq->entery[pq->front]);
}

int RearQueue(Queue* pq) {
    return (pq->entery[pq->rear]);
}

int main()
{
    int rear;
    int front;
    Queue q;
    CreatQueue(&q);
    Append(5, &q);
    rear = RearQueue(&q);
    front = FrontQueue(&q);
    printf("Rear is : %d  and Front is :%d \n", rear, front);
    Append(6, &q);
    rear = RearQueue(&q);
    front = FrontQueue(&q);
    printf("Rear is : %d  and Front is :%d \n", rear, front);
    Append(7, &q);
    rear = RearQueue(&q);
    front = FrontQueue(&q);
    printf("Rear is : %d  and Front is :%d \n", rear, front);
    int y;
    Serve(&y, &q);
    rear = RearQueue(&q);
    front = FrontQueue(&q);
    printf("Rear is : %d  and Front is :%d \n", rear, front);

    return 0;
}
