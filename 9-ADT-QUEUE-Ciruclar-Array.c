// Empty queue: Front is ahead of rear by 1 cell
// Full queue: Front is ahead of rear by 2 cells
// Queue has 1 element: Front is equal to rear
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

void initializeQueue(QUEUE *Q); // Initialize empty queue
void display(QUEUE Q);          // Display the content of the queue
void ENQUEUE(char x, QUEUE *Q); // Insert element into the queue
void DEQUEUE(QUEUE *Q);         // Delete element into the queue
char FRONT(QUEUE Q);            // Return the front element
int isEmpty(QUEUE Q);           // Check if queue is empty
int isFull(QUEUE Q);            // Check if queue is full

int main()
{
    QUEUE A;

    printf("After initializing:\n");
    initializeQueue(&A);
    display(A);

    printf("\nAfter enqueuing:\n");
    ENQUEUE('Q', &A);
    ENQUEUE('U', &A);
    ENQUEUE('E', &A);
    ENQUEUE('U', &A);
    ENQUEUE('E', &A);
    display(A);

    printf("\nFront: %c\n", FRONT(A));

    printf("\nAfter dequeuing:\n");
    DEQUEUE(&A);
    DEQUEUE(&A);
    display(A);

    printf("\nFront: %c\n", FRONT(A));

    (isEmpty(A) == 1) ? printf("\nQueue is empty.\n") : printf("\nQueue is NOT empty.\n");

    (isFull(A) == 1) ? printf("\nQueue is full.\n") : printf("\nQueue is NOT full.\n");

    return 0;
}

void initializeQueue(QUEUE *Q)
{
    Q->front = 1;
    Q->rear = 0;
}

void display(QUEUE Q)
{
    if (Q.front == 1 && Q.rear == 0)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        int n;
        for (n = Q.front; n != (Q.rear + 1) % MAX; n = (n + 1) % MAX)
        {
            printf("%c\n", Q.elem[n]);
        }
    }
}

void ENQUEUE(char x, QUEUE *Q)
{
    // Insertion is invalid when queue is full
    if ((Q->rear + 2) % MAX != Q->front)
    {
        Q->rear = (Q->rear + 1) % MAX;
        Q->elem[Q->rear] = x;
    }
}

void DEQUEUE(QUEUE *Q)
{
    // Deletion is invalid if Queue is empty
    if ((Q->rear + 1) % MAX != Q->front)
    {
        Q->front = (Q->front + 1) % MAX;
    }
}

char FRONT(QUEUE Q)
{
    return Q.elem[Q.front];
}

int isEmpty(QUEUE Q)
{
    return (Q.front == 1 && Q.rear == 0) ? 1 : 0;
}

int isFull(QUEUE Q)
{
    return ((Q.rear + 2) % MAX == Q.front) ? 1 : 0;
}