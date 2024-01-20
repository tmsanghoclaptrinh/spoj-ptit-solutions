#include <iostream>
using namespace std;

// Prototype của hàm con
char findLetter(int k, int N, int S[]);

int main()
{
    int N;
    cin >> N;

    int S[30];
    S[0] = 3; // Khi k = 0 thì chuỗi sẽ có 3 ký tự là "moo"

    // Tạo danh sách độ dài của chuỗi thứ k, cho đến khi S[k] >= N
    int k = 0;
    do
    {
        k++;
        S[k] = S[k - 1] * 2 + (k + 3);
    }
    while (S[k] < N);

    // Thực hiện tìm kiếm xem vị trí thứ N là ký tự 'm' hay ký tự 'o'
    cout << findLetter(k, N, S);

    return 0;
}

// Hàm thực hiện tìm kiếm xem vị trí thứ N là ký tự 'm' hay ký tự 'o'
char findLetter(int k, int N, int S[])
{
    // Ví dụ N = 8 sẽ rơi vào trường hợp này
    // Vì khi đó ta sẽ đệ quy đến findLetter(0, N - 7), tức là k mới = 0, N mới = 1
    if (k == 0)
    {
        if (N == 1)
        {
            return 'm';
        }
        else
        {
            return 'o';
        }
    }

    int lengthOfFirstPart = S[k - 1];

    // Nếu N nằm trong đoạn đầu của chuỗi
    if (N <= lengthOfFirstPart)
    {
        return (findLetter(k - 1, N, S));
    }

    // Nếu N là vị trí (lengthOfFirstPart + 1) thì đó chính là vị trí của ký tự 'm' của đoạn giữa chuỗi.
    // Vì đoạn giữa chuỗi sẽ bắt đầu bằng chữ 'm' và theo sau là (k+2) chữ 'o'
    if (N == lengthOfFirstPart + 1)
    {
        return 'm';
    }

    // Nếu N là vị trí của một trong những chữ 'o' còn lại trong đoạn giữa của chuỗi
    int lengthFromBeginToEndOfSecondPart = lengthOfFirstPart + k + 3;
    if ((lengthOfFirstPart + 1 < N) && (N <= lengthFromBeginToEndOfSecondPart))
    {
        return 'o';
    }

    // Nếu N nằm trong đoạn cuối chuỗi. Đoạn cuối chuỗi chính là một chuỗi S(k-1) khác
    // Do đó ta có thể giảm bớt N cho dễ tìm, bằng cách lấy N trừ đi độ dài từ đầu cho đến hết đoạn giữa chuỗi
    return (findLetter(k - 1, N - lengthFromBeginToEndOfSecondPart, S));
}
