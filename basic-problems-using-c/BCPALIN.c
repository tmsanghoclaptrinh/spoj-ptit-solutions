#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int number);
int reverse(int number);

int main()
{
    int numberOfTestCases;
    scanf("%i", &numberOfTestCases);

    while (numberOfTestCases--)
    {
        int number;
        scanf("%i", &number);

        if (isPalindrome(number))
        {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
}

bool isPalindrome(int number)
{
    int reverseNumber = reverse(number);

    if (reverseNumber == number) 
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

int reverse(int number)
{
    int reverseNumber = 0;
    int temporaryNumber = number;
    
    while (temporaryNumber != 0)
    {
        reverseNumber = (reverseNumber * 10) + (temporaryNumber % 10);
        temporaryNumber /= 10;
    }

    return reverseNumber;
}
