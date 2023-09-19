#include <iostream>

using namespace std;

bool isPrime(int number);

int main() 
{
    int number;
    cin >> number;
    
    if (isPrime(number))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}

bool isPrime(int number)
{
    if (number < 2)
    {
        return false;
    }

    for (int i = 2; i*i <= number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;
}