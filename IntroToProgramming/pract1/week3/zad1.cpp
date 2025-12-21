#include <iostream>
using namespace std;

int main()
{
    //Задача 1: Напишете програма, която приема две естествени числа и връща най-малкото общо кратно.
    int a;
    int b;
    cin >> a >> b;
    int max = a > b ? a : b;
    int min = a < b ? a : b;
    int cand = max;
    while (cand % min != 0)
    {
        cand += max;
    }
    cout << cand;
}