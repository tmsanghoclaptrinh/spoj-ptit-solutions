#include <iostream>
#include <string>

using namespace std;

// Prototype của hàm con
void processTestCases(int numberOfTestCases);

int main()
{
    // Nhập số bộ test
    int numberOfTestCases;
    cin >> numberOfTestCases;

    // Xử lý từng test case
    processTestCases(numberOfTestCases);
    
    return 0;
}

// Hàm xử lý từng test case
void processTestCases(int numberOfTestCases)
{

    for (int testCase = 0; testCase < numberOfTestCases; testCase++)
    {
        // Lần lượt nhập vào <Số thứ tự> <Số lần lặp R> <Chuỗi S>
        int order;
        int repeat;
        string inputString;
        cin >> order >> repeat >> inputString;

        // In số thứ tự bộ test
        cout << order << " ";

        // Duyệt qua từng ký tự trong chuỗi S, mỗi ký tự lặp lại R lần
        for (int i = 0; i < inputString.length(); i++)
        {
            for (int j = 0; j < repeat; j++)
            {
                cout << inputString[i];
            }
        }

        cout << endl;
    }
}
