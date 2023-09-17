#include <stdio.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0

void generateAllPermutations(int numberOfElements);
void generateFirstAscendingPermutation(int numberOfElements, int permutationArray[]);
void printCurrentPermutationArray(int numberOfElements, int permutationArray[]);
void generateNextPermutationArray(int numberOfElements, int permutationArray[], bool *stop);
int findPivot(int numberOfElements, int permutationArray[]);
int findRightmostSuccessorOfPivotInTheSuffix(int pivot, int numberOfElements, int permutationArray[]);
void swap(int *a, int *b);
void reverseTheSuffix(int index, int numberOfElements, int permutationArray[]);

int main()
{
    int numberOfElements;
    scanf("%i", &numberOfElements);
    generateAllPermutations(numberOfElements);
}

void generateAllPermutations(int numberOfElements)
{
    int permutationArray[numberOfElements];
    generateFirstAscendingPermutation(numberOfElements, permutationArray);

    bool stop = FALSE;
    while (!stop)
    {
        printCurrentPermutationArray(numberOfElements, permutationArray);
        generateNextPermutationArray(numberOfElements, permutationArray, &stop);
    }
}

void generateFirstAscendingPermutation(int numberOfElements, int permutationArray[])
{
    for (int i = 0; i < numberOfElements; i++)
    {
        permutationArray[i] = i + 1;
    }
}

void printCurrentPermutationArray(int numberOfElements, int permutationArray[])
{
    for (int i = 0; i < numberOfElements; i++)
    {
        printf("%i", permutationArray[i]);
    }
    printf("\n");
}

void generateNextPermutationArray(int numberOfElements, int permutationArray[], bool *stop)
{
    int pivot = findPivot(numberOfElements, permutationArray);

    if (pivot < 0)
    {
        *stop = TRUE;
    }
    else
    {
        int rightmostSuccessorOfPivotInTheSuffix = findRightmostSuccessorOfPivotInTheSuffix(pivot, numberOfElements, permutationArray);
        swap(&permutationArray[pivot], &permutationArray[rightmostSuccessorOfPivotInTheSuffix]);
        reverseTheSuffix(pivot, numberOfElements, permutationArray);
    }
}

int findPivot(int numberOfElements, int permutationArray[])
{
    int index = numberOfElements - 2;

    while ((index >= 0) && (permutationArray[index] > permutationArray[index + 1]))
    {
        index--;
    }

    return index;
}

int findRightmostSuccessorOfPivotInTheSuffix(int pivot, int numberOfElements, int permutationArray[])
{
    int rightmostSuccessorOfPivotInTheSuffix = numberOfElements - 1;
    
    while (permutationArray[rightmostSuccessorOfPivotInTheSuffix] < permutationArray[pivot])
    {
        rightmostSuccessorOfPivotInTheSuffix--;
    }

    return rightmostSuccessorOfPivotInTheSuffix;
}

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void reverseTheSuffix(int index, int numberOfElements, int permutationArray[])
{
    int left = index + 1;
    int right = numberOfElements - 1;
    while (left < right)
    {
        swap(&permutationArray[left], &permutationArray[right]);
        left++;
        right--;
    }
}