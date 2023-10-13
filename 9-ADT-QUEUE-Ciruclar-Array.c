#include <stdio.h>
#include <stdlib.h>
#define MAX 8

// Definition
typedef struct node
{
    char elem[MAX];
    int front;
    int rear;
} QUEUE;

void initializeQueue(QUEUE *Q);
void display(QUEUE Q);
void ENQUEUE(char x, QUEUE *Q);
void DEQUEUE(char x, QUEUE *Q);

int main()
{
    return 0;
}

void initializeQueue(QUEUE *Q)
{
    // Empty queue: Front is ahead of rear by 1 cell
    Q->front = 1;
    Q->rear = 0;
}

void display(QUEUE Q)
{
}

void ENQUEUE(char x, QUEUE *Q)
{
    // Insertion is invalid when queue is full
    // Full queue: Front is ahead of rear by 2 cells
    if ((Q->rear + 2) % MAX != Q->front)
    {
        Q->rear = (Q->rear + 1) % MAX;
        Q->elem[Q->rear] = x;
    }
}

void DEQUEUE(char x, QUEUE *Q)
{
    // Deletion is invalid if Queue is empty
    // Empty queue: Front is ahead of rear by 1 cell
    if ((Q->rear + 1) % MAX != Q->front)
    {
        Q->front = (Q->front + 1) % MAX;
    }
}