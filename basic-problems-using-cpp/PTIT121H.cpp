#include <iostream>
using namespace std;

int main()
{
    int numberOfCards;
    int k;
    string moves;

    cin >> numberOfCards >> k >> moves;

    // Khởi tạo mảng các lá bài
    int cards[numberOfCards];
    for (int i = 0; i < numberOfCards; i++)
    {
        cards[i] = i;
    }

    // Giải quyết bài toán bằng cách tracking vị trí của lá bài trên cùng (top)
    int top = 0;
    for (int i = 0; moves[i] != '.'; i++)
    {
        // Nếu gặp cách di chuyển A (Lấy quân bài ở trên cùng và chuyển nó xuống dưới cùng của bộ bài)
        // thì vị trí "top mới" chính là vị trí tiếp theo trong bộ bài
        // Ta cần chia modulo cho số lá bài, để nếu top cũ là vị trí cuối cùng trong mảng (numberOfCards - 1),
        // thì (top + 1) % numberOfCards = 0, tức là quay vòng về vị trí đầu tiên trong mảng
        if (moves[i] == 'A')
        {
            top = (top + 1) % numberOfCards;
        }

        // Nếu gặp cách di chuyển B (Lấy quân bài ở vị trí thứ hai từ trên xuống và chuyển nó xuống dưới cùng của bộ bài)
        // thì ta sẽ đổi chỗ 2 lá bài ở vị trí top và vị trí kế tiếp của nó,
        // bởi vì, khi đặt lá bài thứ 2 xuống cuối, thì cũng tương đương với việc xoay vòng lá bài thứ 2 đó lên trước lá bài trên cùng
        // vị trí top mới lúc này cũng được dịch chuyển theo 1 đơn vị
        else
        {
            int temp = (top + 1) % numberOfCards;
            swap(cards[top], cards[temp]);
            top = temp;
        }
    }

    // Vị trí của lá bài thứ k lúc này sẽ được tính từ vị trí top, và bằng (top + k)
    // Từ đó ta tính được vị trí của là bài thứ k - 1 là (top + k - 1)
    // Còn lá bài thứ k + 1 là (top + k + 1)
    // Chia modulo cho numberOfCards để phục vụ cho các trường hợp xoay vòng
    cout << cards[(top + k - 1) % numberOfCards] << " " << cards[(top + k) % numberOfCards] << " " << cards[(top + k + 1) % numberOfCards];

    return 0;
}
