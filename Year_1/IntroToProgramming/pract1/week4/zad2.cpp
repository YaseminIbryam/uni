#include <iostream>
using namespace std;

bool isDigit(char symbol)
{
    return (symbol >= '0' && symbol <= '9'); 
}

bool isLower(char symbol)
{
    return(symbol >= 'a' && symbol <= 'z');
}

bool isUpper(char symbol)
{
    return(symbol >= 'A' && symbol <= 'A');
}

int main()
{
    //Задача 2: Напишете функция isDigit(char symbol), която приема символ и определя дали е число.
    cout << isDigit('a') << endl;
    cout << isDigit('0') << endl;
    cout << isDigit('B') << endl;

}