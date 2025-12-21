#include <iostream>
using namespace std;

int main()
{
    //Задача 3.5: Да се напише програма, която приема 2 числa - a и b и отпечатва всички прости числа в интервала [a, b].
    int a;
    int b;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        bool isPrime = true;
        for(int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            cout << i << " ";
        }
    }
}