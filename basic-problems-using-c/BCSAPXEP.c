#include <stdio.h>

void pushInputElementsToArray(int numberOfElements, int numbers[]);
void printAllElementsInArray(int numberOfElements, int numbers[]);

void bubbleSort(int numberOfElements, int numbers[]);
void swap(int *a, int *b);

int main()
{
    int numberOfElements;
    scanf("%i", &numberOfElements);

    int numbers[1000];

    pushInputElementsToArray(numberOfElements, numbers);

    bubbleSort(numberOfElements, numbers);

    printAllElementsInArray(numberOfElements, numbers);
}

void pushInputElementsToArray(int numberOfElements, int numbers[])
{
    for (int i = 0; i < numberOfElements; i++)
    {
        scanf("%i", &numbers[i]);
    }
}

void printAllElementsInArray(int numberOfElements, int numbers[])
{
    for (int i = 0; i < numberOfElements; i++)
    {
        printf("%i\n", numbers[i]);
    }
}

void bubbleSort(int numberOfElements, int numbers[])
{
    for (int i = 0; i < numberOfElements - 1; i++)
    {
        for (int j = i + 1; j < numberOfElements; j++)
        {
            if (numbers[i] > numbers[j])
            {
                swap(&numbers[i], &numbers[j]);
            }
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
