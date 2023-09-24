#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE_QUEUE 1000
#define TRUE 1
#define FALSE 0
#define OPERATION_GET_SIZE 1
#define OPERATION_CHECK_EMPTY 2
#define OPERATION_ENQUEUE 3
#define OPERATION_DEQUEUE 4
#define OPERATION_GET_FRONT_ITEM 5
#define OPERATION_GET_BACK_ITEM 6
#define EMPTY_QUEUE -1

typedef struct node
{
    int item;
    struct node *next;
} node;

typedef struct queue
{
    int size;
    node *front;
    node *back;
} queue;

void initQueue(queue *workingQueue);
int getSize(queue *workingQueue);
bool isEmpty(queue *workingQueue);
void enqueue(queue *workingQueue, int newItem);
void dequeue(queue *workingQueue);
int getFront(queue *workingQueue);
int getBack(queue *workingQueue);

int main()
{
    int numberOfTestCases;
    scanf("%i", &numberOfTestCases);

    queue *workingQueue = malloc(sizeof(queue));
    initQueue(workingQueue);

    while (numberOfTestCases--)
    {
        int operation;
        scanf("%i", &operation);

        if (operation == OPERATION_GET_SIZE)
        {
            printf("%i\n", getSize(workingQueue));
        }

        if (operation == OPERATION_CHECK_EMPTY)
        {
            if (isEmpty(workingQueue))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }

        if (operation == OPERATION_ENQUEUE)
        {
            int newItem;
            scanf("%i", &newItem);
            enqueue(workingQueue, newItem);
        }

        if (operation == OPERATION_DEQUEUE)
        {
            if (!isEmpty(workingQueue))
            {
                dequeue(workingQueue);
            }
        }

        if (operation == OPERATION_GET_FRONT_ITEM)
        {
            if (!isEmpty(workingQueue))
            {
                printf("%i\n", getFront(workingQueue));
            }
            else
            {
                printf("%i\n", EMPTY_QUEUE);
            }
        }

        if (operation == OPERATION_GET_BACK_ITEM)
        {
            if (!isEmpty(workingQueue))
            {
                printf("%i\n", getBack(workingQueue));
            }
            else
            {
                printf("%i\n", EMPTY_QUEUE);
            }
        }
    }

    free(workingQueue);
}

void initQueue(queue *workingQueue)
{
    workingQueue->size = 0;
    workingQueue->front = NULL;
    workingQueue->back = NULL;
}

int getSize(queue *workingQueue)
{
    return workingQueue->size;
}

bool isEmpty(queue *workingQueue)
{
    return (workingQueue->size == 0);
}

void enqueue(queue *workingQueue, int newItem)
{
    node *newNode = malloc(sizeof(node));
    newNode->item = newItem;
    newNode->next = NULL;

    if (isEmpty(workingQueue))
    {
        workingQueue->front = newNode;
        workingQueue->back = newNode;
    }
    else
    {
        workingQueue->back->next = newNode;
        workingQueue->back = workingQueue->back->next;
    }

    (workingQueue->size)++;
}

void dequeue(queue *workingQueue)
{
    if (!isEmpty(workingQueue))
    {
        (workingQueue->size)--;
        node *currentFrontNode = workingQueue->front;
        workingQueue->front = workingQueue->front->next;
        free(currentFrontNode);
    }
}

int getFront(queue *workingQueue)
{
    return workingQueue->front->item;
}

int getBack(queue *workingQueue)
{
    return workingQueue->back->item;
}