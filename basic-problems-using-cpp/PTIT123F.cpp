#include <iostream>
using namespace std;

// Prototype của các hàm con
void playGame(int numberOfCells);
int countEscapedPrisoners(bool openedCells[], int numberOfCells);

int main()
{
    // Nhập vào số bộ test
    int numberOfTestCases;
    cin >> numberOfTestCases;

    while (numberOfTestCases--)
    {
        // Nhập số ô của nhà tù
        int numberOfCells;
        cin >> numberOfCells;

        // Cai ngục chơi trò chơi
        playGame(numberOfCells);
    }

    return 0;
}

void playGame(int numberOfCells)
{
    // Bạn đầu tất cả các ô đều bị khóa
    // false: khóa, true: mở
    bool openedCells[numberOfCells + 1] = {false};

    // Sau mỗi vòng chơi, kiểm tra xem ô nào có index chia hết cho i thì sẽ thay đổi trạng thái
    // khóa -> mở và mở -> khóa
    for (int i = 1; i <= numberOfCells; i++)
    {
        for (int j = i; j <= numberOfCells; j += i)
        {
            openedCells[j] = !openedCells[j];
        }
    }

    // Đếm số tù nhân trốn thoát
    int totalEscapedPrisoners = countEscapedPrisoners(openedCells, numberOfCells);

    // In ra số tù nhân trốn thoát
    cout << totalEscapedPrisoners << "\n";
}

// Hàm đếm số tù nhân trốn thoát
int countEscapedPrisoners(bool openedCells[], int numberOfCells)
{
    int totalEscapedPrisoners = 0;

    for (int i = 1; i <= numberOfCells; i++)
    {
        if (openedCells[i])
        {
            totalEscapedPrisoners++;
        }
    }

    return totalEscapedPrisoners;
}
