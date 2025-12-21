#include <iostream>
using namespace std;

void reduction(int& a, int& b)
{
    int min = a < b ? a:b;
    for (int i = min; i >= 2; i--){
        if (a % i == 0 && b % i == 0) {
            a /= i;
            b /= i;
        }
    }
}

void add_fractions(int& a, int& b, int& c, int& d) {
    int max = b > d ? b:d;
    int min = b < d ? b:d;
    int lcm = max;
    while (lcm % min != 0) {
        lcm += max;
    }
    int multiply1 = lcm / b;
    int multiply2 = lcm / d;
    a *= multiply1;
    c *= multiply2;
    b = lcm;
    d = lcm;
    a = a + c;
    b = lcm;
    reduction(a, b);
    
}
//Задача 2: Създайте фунция, която приема 2 цели числа - числител и знаменател, и съкращава дробта.
//Бонус: Напишете програма, която извежда сбора на 2 такива дробни числа.
int main()
{
    int a;
    int b;
    int c;
    int d;
    cin >> a >> b >> c >> d;
    add_fractions(a, b, c, d);
    cout << a << " " << b;

}