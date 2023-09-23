#include <iostream>

using namespace std;

bool isPalindrome(int number);
int reverse(int number);

int main()
{
    int numberOfTestCases;
    cin >> numberOfTestCases;

    while (numberOfTestCases--)
    {
        int number;
        cin >> number;

        if (isPalindrome(number))
        {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}

bool isPalindrome(int number)
{
    int reverseNumber = reverse(number);

    if (reverseNumber == number) 
    {
        return true;
    }
    else 
    {
        return false;
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
