#include <iostream>
using namespace std;

int main()
{
    //Задача 9: Да се напише програма, която приема цяло положително число n (n >= 2) и след това n цели числа. Да се отпечатат най-голямато и второто по големина.
    int n;
    cin >> n;
    int maxN;
    int secondMaxN;
    cin >> maxN >> secondMaxN;
    if (maxN < secondMaxN) //swap
    {
        int temp = maxN;
        maxN = secondMaxN;
        secondMaxN = temp;
    }
    int a;
    for (int i = 2; i < n; i++)
    {
        cin >> a;
        if (a > maxN)
        {
            secondMaxN = maxN;
            maxN = a;
        }
        else if (a > secondMaxN)
        {
            secondMaxN = a;
        }
    }
    cout << maxN << " " << secondMaxN;
}