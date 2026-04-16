#include <iostream>
#include "Stack.h"
#include "Stack.cpp"

using namespace std;

void convertDecimalToBinary(int decimal)
{
    Stack<int> result;
    while (decimal > 0)
    {
        result.push(decimal % 2);
        decimal /= 2;
    }
    while (!result.isEmpty())
    {
        cout << result.pop();
    }
}

int main()
{

    int decimalNumber;
    cout << "Enter the decimal number to convert: " << endl;
    cin >> decimalNumber;
    convertDecimalToBinary(decimalNumber);

    return 0;
}