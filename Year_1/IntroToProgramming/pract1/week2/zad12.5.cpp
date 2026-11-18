#include <iostream>
using namespace std;

int main()
{
    //Задача 12.5: (Бонус/За домашно) Добавете и годината. Добавете нужната валидация в случай, че годината е високосна.
    int day = 0;
    int month = 0;
    int year = 0;
    bool isValidDate = 0;
    bool isLeapYear = 0;
    cin >> day >> month >> year;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        isLeapYear = true;
    }
    if (month == 2)
    {
        if ((isLeapYear && (day >= 1 && day <= 29)) || (day >= 1 && day <= 28)) 
        {
            isValidDate = true;
            if (day == 1)
            {
                day = 31;
                month = 1;
            }
            else
            {
                day--;
            }
        }
        else 
        {
            cout << "Not a valid day!";
        }
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day >= 1 && day <= 31 )
        {
            isValidDate = true;
            if (day == 1 )
            {
                if (month == 1)
                {
                    day = 31;
                    month = 12;
                    year--;
                }
                else if (month == 8)
                {
                    day = 31;
                    month = 7;
                }
                else if (month == 3)
                {
                    month = 2;
                    if (isLeapYear)
                    {
                        day = 29;
                    }
                    else
                    {
                        day = 28;
                    }
                }
                else
                {
                    day = 30;
                    month--;
                }

            }
            else
            {
                day--;
            }
        }
        else 
        {
            cout << "Not a valid day!";
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day >= 1 && day <= 30)
        {
            isValidDate = true;
            if (day == 1)
            {
                day = 31;
                month--;
            }
            else
            {
                day--;
            }
        }
        else 
        {
            cout << "Not a valid day!";
        }
    }
    else
    {
        cout << "Not a valid month!";
    }
    if (isValidDate)
    {
        cout << day << " " << month << " " << year;
    }
}