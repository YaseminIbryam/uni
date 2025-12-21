#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(const char* str) {
    //Задача 2: Да се напише функция, която приема симовлен низ и проверява дали низът е палиндром
    //Упътване: На семинарите сте разглеждали оператор++ за указатели. Знаете, че ++ptr премества указателя една позиция надясно. Операторът -- прави нещо подобно само, че, както вероятно се досещате, мести указателя наляво.
    if (str == nullptr) {
        return true;
    }

    const char* end = str + strlen(str) - 1;
    while (str < end)
    {
        if (*str != *end) {
            
        }
    }
}

int main(){


}