#include <iostream>

using namespace std;

// Constant
#define BIT_0 0
#define BIT_1 1

// Prototype
void generateAllBinaryArrays(int numberOfBits);
void generateAllBitZeroIntoArray(int numberOfBits, int binaryArray[]);
void printBinaryArray(int numberOfBits, int binaryArray[]);
void generateNextBinaryArray(int numberOfBits, int binaryArray[], bool *stop);
int findIndexOfFirstBitZeroFromRightToLeft(int numberOfBits, int binaryArray[]);
bool existBitZeroInBinaryArray(int indexOfFirstBitZeroFromRightToLeft);
void updateAllBitsOnRightSideOfIndexToZero(int index, int numberOfBits, int binaryArray[]);

int main()
{
    int numberOfBits;
    cin >> numberOfBits;
    generateAllBinaryArrays(numberOfBits);
}

void generateAllBinaryArrays(int numberOfBits)
{
    int binaryArray[numberOfBits];
    generateAllBitZeroIntoArray(numberOfBits, binaryArray);
    
    bool stop = false;
    while (!stop)
    {
        printBinaryArray(numberOfBits, binaryArray);
        generateNextBinaryArray(numberOfBits, binaryArray, &stop);
    }
}

void generateAllBitZeroIntoArray(int numberOfBits, int binaryArray[])
{
    for (int i = 0; i < numberOfBits; i++)
        binaryArray[i] = BIT_0;
}

void printBinaryArray(int numberOfBits, int binaryArray[])
{
    for (int i = 0; i < numberOfBits; i++)
    {
        cout << binaryArray[i];
    }
    cout << endl;
}

void generateNextBinaryArray(int numberOfBits, int binaryArray[], bool *stop)
{
    int indexOfFirstBitZeroFromRightToLeft = findIndexOfFirstBitZeroFromRightToLeft(numberOfBits, binaryArray);

    if (!existBitZeroInBinaryArray(indexOfFirstBitZeroFromRightToLeft))
    {
        *stop = true;
    }
    else
    {
        binaryArray[indexOfFirstBitZeroFromRightToLeft] = BIT_1;
        updateAllBitsOnRightSideOfIndexToZero(indexOfFirstBitZeroFromRightToLeft, numberOfBits, binaryArray);
    }
}

int findIndexOfFirstBitZeroFromRightToLeft(int numberOfBits, int binaryArray[])
{
    int index = numberOfBits - 1;

    while ((index >= 0) && (binaryArray[index] > BIT_0))
    {
        index--;
    }

    return index;
}

bool existBitZeroInBinaryArray(int indexOfFirstBitZeroFromRightToLeft)
{
    return indexOfFirstBitZeroFromRightToLeft >= 0;
}

void updateAllBitsOnRightSideOfIndexToZero(int index, int numberOfBits, int binaryArray[])
{
    for (int i = index + 1; i < numberOfBits; i++)
        binaryArray[i] = BIT_0;
}
