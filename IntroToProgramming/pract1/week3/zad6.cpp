#include <iostream>
using namespace std;

int main()
{
    //Задача 6: Да се напише програма, която приема цяло число и премахва среднaта цифра, ако числото има нечетен брой цифри или премахва средните две цифри, ако числото има четен брой цифри. Отпечатайте полученото число след премахването.
    int n;
    cin >> n;
    int digits = 0;
    int copyN = n;
    while (copyN != 0)
    {
        copyN /= 10;
        digits ++;
    }
    if (digits == 1)
    {
        cout << 0;
    }
    else
    {
        int numberBackwards = 0;
        for (int i = 1; i <= digits; i++)
        {
            if (i == digits / 2 + 1 || (i == digits / 2 && digits % 2 == 0))
            {
                n /= 10;
                continue;
            }
            numberBackwards *= 10;
            numberBackwards += n % 10;
            n /= 10;
        
        }
        while (numberBackwards != 0)
        {
            cout << numberBackwards % 10;
            numberBackwards /= 10; 
        }
    }
}