#include <iostream>
using namespace std;

// Prototype của hàm con
bool checkMatch(string fileName, string formatName);

int main()
{
    // Nhập vào định dạng tên file cho trước
    string formatName;
    cin >> formatName;

    // Nhập vào số bộ test
    int numberOfTestCases;
    cin >> numberOfTestCases;

    // Xử lý từng bộ test
    while (numberOfTestCases--)
    {
        // Nhập vào tên file
        string fileName;
        cin >> fileName;

        // Kiểm tra tên file có đúng format không
        bool isMatching = checkMatch(fileName, formatName);

        // Nếu trùng thì in ra tên file đó
        if (isMatching)
        {
            cout << fileName << endl;
        }
    }

    return 0;
}

// Hàm kiểm tra fileName có khớp với formatName hay không
bool checkMatch(string fileName, string formatName)
{
    bool isMatching = true; // Cờ dùng để kiểm tra fileName có khớp với định dạng của formatName hay không
    int indexInFormatName = formatName.length() - 1; // Dùng để duyệt qua từng ký tự của formatName
    int indexInFileName = fileName.length() - 1;   // Dùng để duyệt qua từng ký tự của fileName

    // Chạy vòng lặp để kiểm tra fileName có khớp với formatName hay không
    while (indexInFormatName >= 0 || indexInFileName >= 0)
    {
        // Nếu gặp ký tự '*' thì
        if (formatName[indexInFormatName] == '*')
        {
            // Tiếp tục duyệt formatName đến khi nào gặp ký tự khác ký tự '*'
            while ((formatName[indexInFormatName] == '*') && (indexInFormatName >= 0))
            {
                indexInFormatName--;
            }

            // Nếu duyệt hết formatName vẫn không thấy ký tự nào khác ký tự * (tức là formatName toàn dấu '*') thì thoát khỏi
            // vòng lặp Trường hợp này mọi fileName sẽ đều hợp lệ
            if (indexInFormatName == -1)
            {
                break;
            }

            // Duyệt fileName đến khi nào gặp ký tự trùng với ký tự hiện tại của formatName thì dừng lại
            // Bởi vì những ký tự khác với ký tự hiện tại sẽ tương đương với việc mapping với ký tự * ở formatName
            while ((fileName[indexInFileName] != formatName[indexInFormatName]) && (indexInFileName >= 0))
            {
                indexInFileName--;
            }

            // Nếu duyệt hết fileName không tìm thấy ký tự trùng với ký tự hiện tại của formatName, thì chuỗi này không khớp
            // với format, kết thúc vòng lặp
            if (indexInFileName == -1)
            {
                isMatching = false;
                break;
            }
        }
        // Nếu không gặp ký tự '*' thì so sánh ký tự tương ứng giữa formatName và fileName
        else
        {
            if (formatName[indexInFormatName] != fileName[indexInFileName])
            {
                isMatching = false;
                break;
            }
            else
            {
                indexInFormatName--;
                indexInFileName--;
            }
        }
    }

    return isMatching;
}
