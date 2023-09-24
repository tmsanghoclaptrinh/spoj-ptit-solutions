#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 1000
#define MAX_STRING_SIZE 10
#define TRUE 1
#define FALSE 0
#define EMPTY -1

typedef struct stack
{
    int items[MAX_STACK_SIZE];
    int top;
} stack;

void init(stack *workingStack);
void push(stack *workingStack, int newItem);
void pop(stack *workingStack);
int getTop(stack *workingStack);
int getSize(stack *workingStack);
bool isEmpty(stack *workingStack);

int main()
{
    while (1)
    {
        char operation[MAX_STRING_SIZE];
        scanf("%s", operation);

        stack workingStack;

        if (strcmp(operation, "end") == 0)
        {
            break;
        }

        if (strcmp(operation, "init") == 0)
        {
            init(&workingStack);
        }

        if (strcmp(operation, "push") == 0)
        {
            int newItem;
            scanf("%i", &newItem);
            push(&workingStack, newItem);
        }

        if (strcmp(operation, "pop") == 0)
        {
            pop(&workingStack);
        }

        if (strcmp(operation, "top") == 0)
        {
            printf("%i\n", getTop(&workingStack));
        }

        if (strcmp(operation, "size") == 0)
        {
            printf("%i\n", getSize(&workingStack));
        }

        if (strcmp(operation, "empty") == 0)
        {
            printf("%i\n", isEmpty(&workingStack));
        }
    }
}

void init(stack *workingStack)
{
    workingStack->top = EMPTY;
}

void push(stack *workingStack, int newItem)
{
    (workingStack->top)++;
    workingStack->items[workingStack->top] = newItem;
}

void pop(stack *workingStack)
{
    if (!isEmpty(workingStack))
    {
        (workingStack->top)--;
    }
}

int getTop(stack *workingStack)
{
    if (isEmpty(workingStack))
    {
        return workingStack->top;
    }
    else
    {
        return workingStack->items[workingStack->top];
    }
}

int getSize(stack *workingStack)
{
    return (workingStack->top + 1);
}

bool isEmpty(stack *workingStack)
{
    return (workingStack->top == EMPTY);
}