#include <iostream>
using namespace std;

int main()
{
    //Задача 8: Да се напише програма, която приема две числа - х и у, и проверява в кой квадрант лежи точката с дадените координати.
    int x = 0;
    int y = 0;
    cin >> x >> y;
    if (x > 0 && y > 0)
    {
        cout << "First";
    }
    else if (x < 0 && y > 0)
    {
        cout << "Second";
    }
    else if (x < 0 && y < 0)
    {
        cout << "Third";
    }
    else if (x > 0 && y < 0)
    {
        cout << "Fourth";
    }
    else if (x == 0 && y != 0)
    {
        cout << "y-axis";
    }
    else if (x != 0 && y == 0)
    {
        cout << "x-axis";
    }
    else
    {
        cout << "Origin";
    }

}