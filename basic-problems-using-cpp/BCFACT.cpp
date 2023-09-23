#include <iostream>

using namespace std;

long long calculateFactorial(long long number);

int main()
{
    const long long BREAK_NUMBER = 0;
    while (1)
    {
        long long number;
        cin >> number;

        if (number == BREAK_NUMBER)
        {
            break;
        }

        long long factorial = calculateFactorial(number);

        cout << factorial << endl;
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