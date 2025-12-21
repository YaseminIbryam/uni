#include <iostream>
using namespace std;

int main()
{
    //Задача 4: Напишете програма, която приема цяло число и връща най-често срещаната цифра. Ако има няколко най-често срещани, то да се отпечата най-малката.
    int n;
    cin >> n;
    int maxCount = 0;
    int mostCommon;
    for(int i = 0; i <= 9 ; i++)
    {
        int count = 0;
        int a = n;
        int d;
        while(a != 0)
        {
            d = a % 10;
            a /= 10;
            if (d == i)
            {
                count++;
            }
        }
        if (count > maxCount)
        {
            maxCount = count;
            mostCommon = i;
        }

    }
    cout << mostCommon;
}