#include <stdlib.h>
#include <stdio.h>

#define MAX 100
typedef struct Queue
{
    int *arr;
    int front;
    int rear;

} Queue;

Queue *init()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->arr = (int *)malloc(MAX * sizeof(int));
    q->front = -1;
    q->rear = -1;

    return q;
}

void push(Queue *q, int a)
{

    {
        q->rear = (q->rear + 1) % MAX;
        q->arr[q->rear] = a;
    }
}
void pop(Queue *q)
{
    q->front = (q->front + 1) % MAX;
}

void freeQueue(Queue *q)
{
    if (q->arr != NULL)
    {
        free(q->arr);
    }
    free(q);
}

int main()
{
}