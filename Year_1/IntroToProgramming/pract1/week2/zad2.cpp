//Задача 2: Използвайки тернарен оператор, изведете на конзолата дали въведеното число е четно.
#include <iostream>
using namespace std;


int main()
{
    int number = 0;
    cin >> number;
    cout << ((number % 2 == 0) ? true : false);
}
