#include <iostream>
using namespace std;

int main()
{
    //Задача 9: От конзолата се въвеждат дължините на трите страни на триъгълник (реални положителни числа).Програмата да определи какъв е видът на триъгълника - равностранен, равнобедрен, правоъгълен или нито един от изброените. Валидирайте входните данни. (Подсказка -> уверете се, че триъгълникът съществува)
    double a = 0;
    double b = 0;
    double c = 0;
    cin >> a >> b >> c;
    if (a + b > c && a + c > b && b + c > a)
    {
        if ( a == b &&  b == c)
        {
            cout << "Equilateral triangle";
        }
        else if ( a == b || a == c || b == c)
        {
            cout << "Isoscales triangle";
        }
        else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
        {
            cout << "Right angled triangle";
        }
        else 
        {
            cout << "Simple triangle";
        }
        
    } 
    else 
    {
        cout << "Not a triangle";
    }

}