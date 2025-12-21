#include <iostream>
using namespace std;

int main()
{
    //Задача 5.5: Да се въведат от конзолата 3 цифри и да се изведе най - голямото число, което може да се получи, ако тези цифри са единици, десетици и стотици.
    int a = 0;
    int b = 0;
    int c = 0;
    int max = 0;
    int min = 0;
    int mid = 0;
    cin >> a >> b >> c;
    if (a >= b && a >= c)
    {
        max = a;
    }
    else if (b >= a && b >= c)
    {
        max = b;
    }
    else 
    {
        max = c;
    }
    if (a <= b && a <= b)
    {
        min = a;
    }
    else if (b <= a && b <= c)
    {
        min = b;
    }
    else 
    {
        min = c;
    }
    mid = a + b + c - min - max;
    cout << max * 100 + mid * 10 + min;
}