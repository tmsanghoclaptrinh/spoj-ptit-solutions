#include <stdio.h>

long long calculateFactorial(long long number);

int main()
{
    const long long BREAK_NUMBER = 0;
    while (1)
    {
        long long number;
        scanf("%lld", &number);

        if (number == BREAK_NUMBER)
        {
            break;
        }

        long long factorial = calculateFactorial(number);

        printf("%lld\n", factorial);
    }
}

long long calculateFactorial(long long number)
{
    long long factorial = 1;

    while (number >= 1)
    {
        factorial *= number;
        number--;
    }

    return factorial;
}