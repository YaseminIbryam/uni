#include <iostream>
using namespace std;

int main()
{
    //Задача 7: Да се напише програма, която приема цяло число и отпечатва дали е степен на 2-ката.
    int n;
    cin >> n;
    bool isPowerOfTwo = true;
    if (n <= 0)
    {
        isPowerOfTwo = false;
    }
    while (n > 1)
    {
        if (n % 2 != 0)
        {
            isPowerOfTwo = false;
            break;
        }
        n /= 2;
    }
    cout << isPowerOfTwo;
}