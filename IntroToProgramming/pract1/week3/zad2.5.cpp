#include <iostream>
using namespace std;

int main()
{
    //Задача 2.5: Да се напише програма, която приема 2 числа. Да се отпечатат всички общи делители сортирани низходящо.
    int a;
    int b;
    cin >> a >> b;
    if (b > a)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    while (b != 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    for (int i = a; i >= 1; i--)
    {
        if (a % i == 0)
        {
            cout << i << " ";
        }

    }
}