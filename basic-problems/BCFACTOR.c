#include <stdio.h>

void findPrimeFactors(int number);

int main()
{
    int number;
    scanf("%i", &number);

    findPrimeFactors(number);
}

void findPrimeFactors(int number)
{
    int exponent = 0;
    for (int i = 2; i*i <= number; i++)
    {
        while (number % i == 0)
        {
            number /= i;
            exponent++;
        }

        if (exponent != 0)
        {
            printf("%i %i\n", i, exponent);
            exponent = 0;
        }
    }

    if (number > 1)
    {
        printf("%i 1", number);
    }
}