//Задача 5: От стандартния вход се въвеждат три цели числа. Да се изведе на стандартния изход средното по големина число.
#include <iostream>
using namespace std;

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    cin >> a >> b >> c;
    if (a >= b && a >= c)
    {
        cout << a;
    }
    else if (b >= a && b >= c)
    {
        cout << b;
    }
    else 
    {
        cout << c;
    }
}
