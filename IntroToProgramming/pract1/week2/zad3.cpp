#include <iostream>
using namespace std;

int main()
{
    //Задача 3: От конзолата се въвежда цифра от 2 до 6. Нека на конзолата се изведе коя е съответната оценка, написана с думи.
    int grade = 0;
    cin >> grade;
    if (grade == 2)
    {
       cout << "Fail";
    }
    else if (grade == 3)
    {
       cout << "Passing";
    }
    else if (grade == 4)
    {
       cout << "Good";
    }
    else if (grade == 5)
    {
       cout << "Very good";
    }
    else if (grade == 6)
    {
       cout << "Excelent";
    }
    else
    {
       cout << "Not a valid grade";
    }
}