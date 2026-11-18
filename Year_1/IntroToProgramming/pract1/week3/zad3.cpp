#include <iostream>
using namespace std;

int main()
{
    //Задача 3: Напишете програма, която приема естествено число и връща дали числото е просто.
    int num;
    cin >> num;
    bool isPrime = true;
    for(int i = 2; i*i <= num; i++)
    {
        if (num % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    if(isPrime)
		cout << "Prime";
	else
		cout << "Not prime";
}