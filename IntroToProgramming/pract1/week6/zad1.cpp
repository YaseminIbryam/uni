#include <iostream>
using namespace std;

void int_swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void double_swap(double& a, double& b)
{
    double temp = a;
    a = b;
    b = temp;
}


//Задача 1: Да се напише функция swap, която приема две числa и разменя стойностите им. Създайте няколко имплементации на тази функция, така че тя да работи за int, double (добавете и още типове, ако желаете).
int main()
{
    double a;
    double b;
    cin >> a >> b;
    double_swap(a, b);
    cout << a << " " << b;
}