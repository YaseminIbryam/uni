#include <iostream>
using namespace std;

bool isUpper(char symbol)
{
    return(symbol >= 'A' && symbol <= 'Z');
}

bool isLower(char symbol)
{
    return(symbol >= 'a' && symbol <= 'z');
}

char toUpper(char symbol)
{
    if (isLower(symbol))
    {
        symbol -= 32;
    }
    return symbol;
}

char toLower(char symbol)
{
    if (isUpper(symbol))
    {
        symbol += 32;
    }
    return symbol;
}

int main()
{
    cout << toUpper('a') << endl;
    cout << toLower('A') << endl;
}