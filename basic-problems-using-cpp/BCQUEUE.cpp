#include <iostream>
#include <queue>

using namespace std;

#define OPERATION_GET_SIZE 1
#define OPERATION_CHECK_EMPTY 2
#define OPERATION_ENQUEUE 3
#define OPERATION_DEQUEUE 4
#define OPERATION_GET_FRONT_ITEM 5
#define OPERATION_GET_BACK_ITEM 6
#define EMPTY_QUEUE -1

queue<int> workingQueue;

int main()
{
    int numberOfTestCases;
    cin >> numberOfTestCases;

    while (numberOfTestCases--)
    {
        int operation;
        cin >> operation;

        if (operation == OPERATION_GET_SIZE)
        {
            cout << workingQueue.size() << endl;
        }

        if (operation == OPERATION_CHECK_EMPTY)
        {
            if (workingQueue.empty())
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }

        if (operation == OPERATION_ENQUEUE)
        {
            int newItem;
            cin >> newItem;
            workingQueue.push(newItem);
        }

        if (operation == OPERATION_DEQUEUE)
        {
            if (!workingQueue.empty())
            {
                workingQueue.pop();
            }
        }

        if (operation == OPERATION_GET_FRONT_ITEM)
        {
            if (!workingQueue.empty())
            {
                cout << workingQueue.front() << endl;
            }
            else
            {
                cout << EMPTY_QUEUE << endl;
            }
        }

        if (operation == OPERATION_GET_BACK_ITEM)
        {
            if (!workingQueue.empty())
            {
                cout << workingQueue.back() << endl;
            }
            else
            {
                cout << EMPTY_QUEUE << endl;
            }
        }
    }
}