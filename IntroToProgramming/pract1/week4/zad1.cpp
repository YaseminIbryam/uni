#include <iostream>
using namespace std;

int absoluteValue(int x)
    {
        if (x < 0)
        {
            x = -x;
        }
        return x;
    }


int main()
{
    int num;
    cin >> num;
    cout << absoluteValue(num);
}
