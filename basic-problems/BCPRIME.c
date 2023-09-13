#include <stdio.h>
#include <stdbool.h>

bool isPrime(int number);

int main() 
{
    int number;
    scanf("%i", &number);
    
    if (isPrime(number))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}

bool isPrime(int number)
{
    if (number < 2)
    {
        return 0;
    }

    for (int i = 2; i*i <= number; i++)
    {
        if (number % i == 0)
        {
            return 0;
        }
    }

    return 1;
}