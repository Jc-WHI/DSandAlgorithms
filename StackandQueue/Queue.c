#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue
{
    int *arr;
    int front;
    int rear;

} Queue;

Queue *init()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->arr = (int *)malloc(100 * sizeof(int));
    q->front = -1;
    q->rear = -1;
    return q;
}
bool isFull(Queue *q)
{
    if (q->rear == 99)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isEmpty(Queue *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void pushQueue(Queue *q, int a)
{
    if (isFull(q))
    {
        return;
    }
    if (q->rear == -1)
    {
        q->front = 0;
        q->rear = 0;
        q->arr[q->rear] = a;
    }
    else
    {
        q->arr[++q->rear] = a;
    }
}
void popQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty");
        return;
    }
    if (q->rear != q->front)
    {
        q->front++;
    }
    else
    {
        q->rear = -1;
        q->front = -1;
    }
}

int main()
{
    Queue *q = init();
    pushQueue(q, 10);
    popQueue(q);
}