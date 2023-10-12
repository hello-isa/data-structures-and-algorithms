#include <stdio.h>
#define MAX 5

// Definition
typedef struct
{
    char data;
    int link;
} member;

typedef struct
{
    member Node[MAX];
    int Avail;
} VirtualHeap;

typedef int List;

// Virtual Heap Management Routine
void initializeVH(VirtualHeap *VH);        // Initialize the Virtual Heap
void initializeList(List *L);              // Initialize the List
int allocSpace(VirtualHeap *VH);           // This is similar to malloc(), needed for insertion
void deallocSpace(VirtualHeap *VH, int n); // This is similar to free(), needed for deletion

void display(VirtualHeap VH, List L);               // Display the content of the list
void insertFirst(VirtualHeap *VH, List *L, char v); // Insert an element at the first index (or head) of the list
void insertLast(VirtualHeap *VH, List *L, char w);  // Insert an element at the last index (or tail) of the list

int main()
{
    VirtualHeap A;
    List B;

    printf("Initialization:\n");
    initializeVH(&A);
    initializeList(&B);
    display(A, B);

    printf("\nInsert first:\n");
    insertFirst(&A, &B, 'a');
    insertFirst(&A, &B, 'b');
    display(A, B);

    return 0;
}

void initializeVH(VirtualHeap *VH)
{
    VH->Avail = MAX - 1;
    int n;

    for (n = 0; n < MAX; n++)
    {
        VH->Node[n].link = n - 1;
    }
}

void initializeList(List *L)
{
    *L = -1;
}

int allocSpace(VirtualHeap *VH)
{
    int temp = -1;
    if (VH->Avail != -1)
    {
        temp = VH->Avail;
        VH->Avail = VH->Node[temp].link;
    }
    return temp;
}

void deallocSpace(VirtualHeap *VH, int n)
{
    VH->Node[n].link = VH->Avail;
    VH->Avail = n;
}

void display(VirtualHeap VH, List L)
{
    List current;
    for (current = L; current != -1; current = VH.Node[current].link)
    {
        printf("%c -> ", VH.Node[current].data);
    }
    printf("NULL\n");
}

void insertFirst(VirtualHeap *VH, List *L, char v)
{
    int newNode = allocSpace(VH); // allocSpace will return the index of the available node

    if (newNode != -1)
    {
        VH->Node[newNode].data = v;
        VH->Node[newNode].link = *L;
        *L = newNode;
    }
}

void insertLast(VirtualHeap *VH, List *L, char w)
{
}