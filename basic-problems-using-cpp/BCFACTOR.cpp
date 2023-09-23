#include <iostream>

using namespace std;

void findPrimeFactors(int number);

int main()
{
    int number;
    cin >> number;

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
            cout << i << " " << exponent << endl;
            exponent = 0;
        }
    }

    if (number > 1)
    {
        cout << number << " " << 1;
    }
}