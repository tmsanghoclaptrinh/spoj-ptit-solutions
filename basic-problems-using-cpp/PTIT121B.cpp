#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Prototype của các hàm con dùng trong chương trình
vector<string> generateGrayCodes(int numberOfBits);
void printGrayCodes(vector<string> grayCodes);

int main()
{
    // Nhập vào số bit
    int numberOfBits;
    cin >> numberOfBits;

    // Sinh danh sách các mã Gray
    vector<string> grayCodes = generateGrayCodes(numberOfBits);

    // In danh sách mã Gray
    printGrayCodes(grayCodes);

    return 0;
}

// Hàm sinh mã Gray
vector<string> generateGrayCodes(int numberOfBits)
{
    // Khởi tạo danh sách mã Gray ban đầu
    vector<string> grayCodes;
    grayCodes.push_back("0");
    grayCodes.push_back("1");

    // Chạy vòng lặp để lần lượt sinh danh sách mã Gray theo số bit
    for (int i = 2; i < pow(2, numberOfBits); i *= 2)
    {
        // Duplicate danh sách mã hiện có, theo thứ tự ngược lại
        for (int j = i - 1; j >= 0; j--)
            grayCodes.push_back(grayCodes[j]);

        // Thêm ký tự "0" vào đầu của nửa phía trước
        for (int j = 0; j < i; j++)
            grayCodes[j] = "0" + grayCodes[j];

        // Thêm ký tự "1" vào đầu của nửa phía sau
        for (int j = i; j < 2 * i; j++)
            grayCodes[j] = "1" + grayCodes[j];
    }

    // Trả về danh sách mã Gray hoàn chỉnh
    return grayCodes;
}

// Hàm in mã Gray
void printGrayCodes(vector<string> grayCodes)
{
    for (int i = 0; i < grayCodes.size(); i++)
        cout << grayCodes[i] << endl;
}
