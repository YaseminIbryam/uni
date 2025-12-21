#include <iostream>
using namespace std;

int main()
{
    //Задача 10: Напишете програма, която приема нечетно естествено число и отпечатва пясъчен часовник.
    int a;
    cin >> a;
    if (a % 2 == 0)
    {
        cout << "Enter an odd number!";
    }
    else
    {
        int spaces = 0;
        for (int i = a; i > 1; i -= 2)
        {  
            for (int i = 0; i < spaces; i++)
            {
                cout << " ";
            }
            for (int j = 1; j <= i; j++)
            {
                cout << "*";
            }
            cout << endl;
            spaces++;
        }
        for (int i = 1; i <= a; i += 2)
        {
            for (int j = spaces; j > 0; j--)
            {
                cout << " ";
            }
            for (int k = 1; k <= i; k++)
            {
                cout << "*";
            }
            
            cout << endl;
            spaces--;
        }
    }
}