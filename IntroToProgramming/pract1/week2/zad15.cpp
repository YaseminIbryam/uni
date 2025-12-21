#include <iostream>
using namespace std;

int main()
{
    //Задача 15: Да се напише програма, която при подадени радиус r и двумерна точка (х, у) проверява дали точката се намира вътре/извън или по контура на окръжност с център (0,0).
    double r = 0;
    double x = 0;
    double y = 0;
    cin >> r >> x >> y;
    double lenght2x = x * x + y * y;
    double r2x = r * r;
    if (lenght2x > r2x)
    {
        cout << "Out of the circle";
    }
    else if (lenght2x < r2x)
    {
        cout << "In the circle";
    }
    else 
    {
        cout << "On the circle";
    }
}