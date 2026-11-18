#include <iostream>
using namespace std;

int main()
{
    //Задача 16: Да се напише програма, която получава 5 латински букви. Първите две от тях са главни и образуват множеството A, където A съдържа всички букви между въпросните две букви, включително самите тях. Вторите две букви са малки и образуват множеството B, където B съдържа всички букви между тях, включително самите тях.

    /*Четем 5-та буква (case insensitive). Да се изведе:

    Дали 5-тата буква принадлежи на обединението на A и B.
    Дали 5-тата буква принадлежи на сечението на A и B.
    Дали 5-тата буква принадлежи на разликата на A с B.
    Без да използвате допълнителни проверки (освен резултатите от предните три условия) определете дали 5-тата буква принадлежи само и единствено в някое от множествата A или B.*/
    char a = 0;
    char b = 0;
    char c = 0;
    char d = 0;
    char e = 0;
    bool firstCondition = 0;
    bool secondCondition = 0;
    bool thirdCondition = 0;
    cin >> a >> b >> c >> d >> e;
    bool inA = 'A' <= e && e <= 'Z';
    bool inB = 'a' <= e && e <= 'z';
    char upperCase = 0;
    char lowerCase = 0;
    if (inA)
    {
        upperCase = e;
        lowerCase = e + 32;
    }
    else if (inB)
    {
        upperCase = e - 32;
        clowerCase = e;
    }
    if (upperCase >= a && upperCase <= b || lowerCase >= c && lowerCase <= d)
    {
        firstCondition = true;
    }
    if (upperCase >= a && upperCase <= b && lowerCase >= c && lowerCase <= d)
    {
        secondCondition = true;
    }
    if ()
    {
        thirdCondition = true;
    }
    cout << (inA && !secondCondition);

}