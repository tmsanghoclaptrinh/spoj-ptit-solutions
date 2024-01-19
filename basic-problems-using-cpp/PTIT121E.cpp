#include <iostream>
#include <map>
#include <stack>

using namespace std;

// Prototype của các hàm con
stack<long long> convertFormulaToStack(string chemicalFormula);
bool isAtom(char letter);
long long calculateMolecularMass(stack<long long> chemicalStack);

int main()
{
    // Nhập vào công thức hóa học
    string chemicalFormula;
    cin >> chemicalFormula;

    // Convert công thức hóa học sang stack
    stack<long long> chemicalStack = convertFormulaToStack(chemicalFormula);

    // Tính khối lượng của hóa chất dựa vào stack
    long long molecularMass = calculateMolecularMass(chemicalStack);
    cout << molecularMass;

    return 0;
}

// Hàm convert công thức hóa học sang stack
stack<long long> convertFormulaToStack(string chemicalFormula)
{
    stack<long long> chemicalStack;
    map<char, long long> atomicMass;
    atomicMass['H'] = 1;
    atomicMass['C'] = 12;
    atomicMass['O'] = 16;
    chemicalFormula = " " + chemicalFormula; // Thêm khoảng trắng để xuống dưới vòng lặp bắt đầu chạy từ index = 1

    for (long long i = 1; i <= chemicalFormula.size(); i++)
    {
        // Gặp dấu mở ngoặc đơn thì thêm số -1 vào đỉnh stack
        if (chemicalFormula[i] == '(')
        {
            chemicalStack.push(-1);
        }

        // Gặp các ký tự 'H' hoặc 'C' hoặc 'O' thì thêm khối lượng của chúng vào đỉnh stack
        if (isAtom(chemicalFormula[i]))
        {
            chemicalStack.push(atomicMass[chemicalFormula[i]]);
        }

        // Gặp các số từ 1 đến 9, thì lấy phần tử ở đỉnh stack ra để nhân với số này, sau đó push ngược lại vào đỉnh stack
        if (chemicalFormula[i] >= '1' && chemicalFormula[i] <= '9')
        {
            if (!chemicalStack.empty())
            {
                long long temp = chemicalStack.top();
                chemicalStack.pop();
                temp *= (chemicalFormula[i] - '0');
                chemicalStack.push(temp);
            }
        }

        // Gặp dấu đóng ngoặc đơn thì chạy vòng lặp để cộng dồn các số lưu trong stack, đến khi nào gặp số -1 (đại diện cho dấu ngoặc đơn)
        if (chemicalFormula[i] == ')')
        {
            long long temp = 0;

            while (!chemicalStack.empty() && chemicalStack.top() != -1)
            {
                long long top = chemicalStack.top();
                chemicalStack.pop();
                temp += top;
            }

            // Kiểm tra nếu stack vẫn chưa rỗng, thì xóa bỏ số -1 (đại diện cho dấu ngoặc đơn) khỏi stack, rồi đẩy số temp đã tính được ở trên vào stack
            if (!chemicalStack.empty() && chemicalStack.top() == -1)
            {
                chemicalStack.pop();
                chemicalStack.push(temp);
            }
        }
    }

    return chemicalStack;
}

// Hàm kiểm tra ký tự truyền vào có phải là nguyên tố hóa học 'H' hoặc 'C' hoặc 'O' hay không
bool isAtom(char letter)
{
    return letter == 'H' || letter == 'C' || letter == 'O';
}

// Hàm tính khối lượng của hóa chất dựa vào stack
long long calculateMolecularMass(stack<long long> chemicalStack)
{
    long long molecularMass = 0;

    // Duyệt qua các số còn lại trong stack để cộng dồn tính ra khối lượng của hóa chất ban đầu
    while (!chemicalStack.empty())
    {
        long long temp = chemicalStack.top();
        chemicalStack.pop();
        if (temp != -1)
        {
            molecularMass += temp;
        }
    }

    return molecularMass;
}
