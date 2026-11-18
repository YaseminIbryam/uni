#include <iostream>
using namespace std;

int main()
{
    //Задача 13: Създайте калкулатор, поддържащ операциите +, -, *, / на две реални числа. От конзолата се прочита число, операция и второ число и се извежда резултатът.
    double a = 0;
    double b = 0;
    char operation = 0;
    cin >> a >> operation >> b;
    if (operation == '+')
    {
        cout << a + b;
    }
    else if (operation == '-')
    {
        cout << a - b;
    }
    else if (operation == '*')
    {
        cout << a * b;
    }
    else if (operation == '/')
    {
        if (b == 0)
        {
            cout << "Error! Cannot divide by zero";
        }
        else
        {
            cout << a / b;
        }

    }
    else 
    {
        cout << "Not a valid operation!";
    }
}