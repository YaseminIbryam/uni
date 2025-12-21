#include <iostream>
using namespace std;

int main()
{
    //Задача 7: Напишете програма, която чете един символ от конзолата и извежда дали той е главна или малка буква и също така дали е гласна или съгласна. Да се изведе обърнатата по капитализация буква (от главна - малка и обратното).
    //(При невалидни данни се извежда съобщение за грешка)
    char a = 0;
    cin >> a;
    bool isUppercase = 0;
    bool isVowel = 0;
    char oppositeCase = 0;
    bool isLetter = 0;
    if (a >= 'A' && a <= 'Z')
    {
        isLetter = true;
        isUppercase = true;
        oppositeCase = a + 32;
        if (a == 'A' || a == 'E' || a == 'U' || a == 'I' || a == 'O')
        {
            isVowel = true;
        }
    }
    else if (a >= 'a' && a <= 'z')
    {
        isLetter = true;
        oppositeCase = a - 32;
        if (a == 'a' || a == 'e' || a == 'u' || a == 'i' || a == 'o')
        {
            isVowel = true;
        }
    }
    else
    {
        cout << "Not a letter";
    }
    if (isLetter)
    {
        if (isUppercase)
        {
            cout << "Uppercase ";
        }
        else
        {
            cout << "Lowercase ";
        }
        if (isVowel)
        {
            cout << "Vowel" << endl;
        }
        else 
        {
            cout << "Consonant" << endl;
        }
        cout << oppositeCase;

    }

}