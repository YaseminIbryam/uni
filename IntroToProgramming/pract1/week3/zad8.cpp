#include <iostream>
using namespace std;

int main()
{
    //Въвеждат се 5 цели числа - a, b, c, d, e. Разглеждаме полинома f(x) = a * x^4 - b * x^3 + c x^2 - d * x + e. Отпечатайте всички цели решения на f(x) >= 0 където x e в интервала [-100, 100]
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    for (int i = -100; i <= 100; i++)
    {
        if ((a * i * i * i * i - b * i * i * i + c * i * i - d * i + e) >= 0)
        {
            cout << i << " ";
        }
    }
}