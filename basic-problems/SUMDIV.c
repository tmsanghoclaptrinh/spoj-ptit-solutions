#include <stdio.h>

long long calculateSumDivisors(long long number);

int main()
{
    int numberOfTestCases;
    scanf("%i", &numberOfTestCases);

    while (numberOfTestCases--)
    {
        long long number;
        scanf("%lld", &number);

        long long sumDivisors = calculateSumDivisors(number);

        printf("%lld\n", sumDivisors);
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