#include <iostream>
using namespace std;

// Prototype của hàm con
bool canDivideIntoTwoGroups(int numberOfPeople);

int main()
{
    int numberOfPeople;

    while (true)
    {
        // Nhập vào số lượng trong bộ test hiện tại
        cin >> numberOfPeople;

        // Nếu nhập số 0 thì kết thúc chương trình
        if (numberOfPeople == 0)
        {
            return 0;
        }

        // Kiểm tra nếu có thể chia n người này thành 2 nhóm theo như đề bài yêu cầu thì in ra "YES"
        // Ngược lại thì in ra "NO"
        if (canDivideIntoTwoGroups(numberOfPeople))
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        cout << endl;
    }

    return 0;
}

// Hàm kiểm tra xem có thể chia n người thành 2 nhóm như đề bài yêu cầu không
bool canDivideIntoTwoGroups(int numberOfPeople)
{
    int friendshipMatrix[100][100]; // Ma trận quan hệ giữa mọi người
    int groupAssignment[100];       // Mảng gán số thứ tự nhóm của từng người

    const int NO_GROUP = 0; // Chưa thuộc nhóm nào
    const int GROUP_1 = 1;  // Thuộc nhóm 1
    const int GROUP_2 = 2;  // Thuộc nhóm 2

    // Nhập từng phần tử trong ma trận quan hệ
    for (int i = 1; i <= numberOfPeople; i++)
    {
        for (int j = 1; j <= numberOfPeople; j++)
        {
            cin >> friendshipMatrix[i][j];
        }
    }

    // Ban đầu mọi người đều chưa thuộc nhóm nào cả
    for (int i = 1; i <= numberOfPeople; i++)
    {
        groupAssignment[i] = NO_GROUP;
    }

    // Xử lý việc gán số thứ tự nhóm cho từng người
    for (int i = 1; i <= numberOfPeople; i++)
    {
        // Nếu chưa thuộc group nào, thì gán vào group số 1
        // Sau đó chạy vòng lặp qua những người còn lại, nếu ai có mối quan hệ với người này thì gán họ vào group số 2
        if (groupAssignment[i] == NO_GROUP)
        {
            groupAssignment[i] = GROUP_1;
            for (int j = i + 1; j <= numberOfPeople; j++)
            {
                if (friendshipMatrix[i][j])
                {
                    groupAssignment[j] = GROUP_2;
                }
            }
        }
        else // Ngược lại, nếu người đang kiểm tra đã thuộc 1 group nào đó, thì chạy vòng lặp qua những người còn lại, nếu ai có mối
             // quan hệ với người này, thì kiểm tra xem người đó đang thuộc group nào, nếu 2 người này trùng group thì return false luôn
        {
            for (int j = 1; j <= numberOfPeople; j++)
            {
                if (friendshipMatrix[i][j])
                {
                    if (groupAssignment[i] == groupAssignment[j])
                    {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}
