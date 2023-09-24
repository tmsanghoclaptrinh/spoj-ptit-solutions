#include <iostream>
#include <stack>

using namespace std;

stack<int> workingStack;

int main()
{
    while (1)
    {
        string operation;
        cin >> operation;
        
        if (operation == "end")
        {
            break;
        }

        if (operation == "init")
        {
            while (!workingStack.empty())
            {
                workingStack.pop();
            }
        }

        if (operation == "push")
        {
            int newItem;
            cin >> newItem;
            workingStack.push(newItem);
        }

        if (operation == "pop")
        {
            if (!workingStack.empty())
            {
                workingStack.pop();
            }
        }

        if (operation == "top")
        {
            if (workingStack.empty())
            {
                cout << "-1" << endl;
            }
            else
                cout << workingStack.top() << endl;
        }

        if (operation == "size")
        {
            cout << workingStack.size() << endl;
        }

        if (operation == "empty")
        {
            if (workingStack.empty())
            {
                cout << "1" << endl;
            }
            else
            {
                cout << "0" << endl;
            }
        }
    }
}
