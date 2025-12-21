#include <iostream>
using namespace std;

int main()
{
    //Задача 10: От конзолата се въвеждат три числа от реалната права. Първото е ляв край на интервал, а второто десният му край. Да се провери дали третото число се съдържа в интервала и ако съвпада с единия му край да се изведе съобщение, че интервалът е затворен. Ако числото е в интервала да се изведе съобщение, че е в интервалът е отворен. Ако не се намира в интервала да се изведе подходящо съобщение.
    double a = 0;
    double b = 0;
    double c = 0;
    cin >> a >> c >> b;
    if (a < b && b < c )
    {
        cout << "The number is within the interval." << endl;
        cout << "The interval is open.";
    }
    else if (a == b || b == c)
    {
        cout << "The interval is closed.";
    }
    else
    {
        cout << "The number is not within the interval.";
    }
}