#include <iostream>

using namespace std;

long long calculateGreatestCommonDivisor(long long firstNumber, long long secondNumber);
long long calculateLeastCommonMultiple(long long firstNumber, long long secondNumber, long long greatestCommonDivisor);

int main()
{
    while(1)
    {
        long long firstNumber, secondNumber;
        cin >> firstNumber >> secondNumber;

        if ((firstNumber == 0) && (secondNumber == 0))
        {
            break;
        }
            
        long long greatestCommonDivisor = calculateGreatestCommonDivisor(firstNumber, secondNumber);
        long long leastCommonMultiple = calculateLeastCommonMultiple(firstNumber, secondNumber, greatestCommonDivisor);
        
        cout << greatestCommonDivisor << " " << leastCommonMultiple << endl;
    }
}

long long calculateGreatestCommonDivisor(long long firstNumber, long long secondNumber)
{
    while (secondNumber != 0)
    {
        long long temp = secondNumber;
        secondNumber = firstNumber % secondNumber;
        firstNumber = temp;
    }

    return firstNumber;
}

long long calculateLeastCommonMultiple(long long firstNumber, long long secondNumber, long long greatestCommonDivisor)
{
    return firstNumber * secondNumber / greatestCommonDivisor; 
}