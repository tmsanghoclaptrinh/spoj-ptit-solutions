#include <iostream>

using namespace std;

long long calculateSumDivisors(long long number);

int main()
{
    int numberOfTestCases;
    cin >> numberOfTestCases;

    while (numberOfTestCases--)
    {
        long long number;
        cin >> number;

        long long sumDivisors = calculateSumDivisors(number);

        cout << sumDivisors << endl;
    }
}

long long calculateSumDivisors(long long dividend)
{
    long long sumDivisors = 0;

    for (long long divisor = 1; (divisor * divisor) <= dividend; divisor++)
    {
        if (dividend % divisor == 0)
        {
            sumDivisors += divisor;
            long long quotient = dividend / divisor;
            if (quotient != divisor)
            {
                sumDivisors += quotient;
            }
        }
    }

    return sumDivisors;
}