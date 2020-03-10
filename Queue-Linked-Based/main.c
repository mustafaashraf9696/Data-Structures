#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef int QueueEntery;

typedef struct queuenode {
	QueueEntery entery;
	struct queuenode* Next;
}QueueNode;

typedef struct queue {
	QueueNode* front;
	QueueNode* rear;
	int Size;
}Queue;

void CreateQueue(Queue* pq) {
	pq->front = NULL;
	pq->rear = NULL;
	pq->Size = 0;
}

void Append(QueueEntery e, Queue* pq) {
	QueueNode* pn = (QueueNode*)malloc(sizeof(QueueNode));
	pn->Next = NULL;
	pn->entery = e;
	if (!pq->rear)
		pq->front = pn;
	else
		pq->rear->Next = pn;
	pq->rear = pn;
	pq->Size++;
}

void Serve(QueueEntery* pe, Queue* pq) {
	QueueNode* pn = pq->front;
	*pe = pn->entery;
	pq->front = pq->front->Next;
	free(pn);
	if (!pq->front)
		pq->rear = NULL;
	pq->Size--;
}

int QueueEmpety(Queue* pq) {
	return (!pq->Size);
}

int QueueFull(Queue* pq) {
	return 0;
}

int QueueSize(Queue* pq) {
	return pq->Size;
}

void ClearQueue(Queue* pq) {
	while (pq->front)
	{
		pq->rear = pq->front->Next;
		free(pq->front);
		pq->front = pq->rear;
	}
	pq->Size = 0;
}

int RearQueue(Queue* pq) {
	return pq->rear->entery;
}

int FrontQueue(Queue* pq) {
	return pq->front->entery;
}

int main() {
	int rear;
	int front;
	Queue q;
	CreateQueue(&q);
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
