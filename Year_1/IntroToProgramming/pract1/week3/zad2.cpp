#include <iostream>
using namespace std;

int main()
{
    int a;
    int b;
    cin >> a >> b;
    int max = a > b ? a : b;
    int min = a < b ? a : b;
    a = max;
    b = min;
    while (b != 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    cout << a;

}