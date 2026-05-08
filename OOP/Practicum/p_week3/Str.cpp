#include <iostream>
#include <cstring>

class Str{
private:
    char* data;

public:
    Str()
    {
        // Rent exactly 1 box, and put the '\0' stop sign inside it.
        // Now it is a valid string of length 0! No more Segfaults!
        data = new char[1];
        data[0] = '\0';
    }
    Str(const char* str):
    data(new char[strlen(str) + 1]{}){
        strcpy(data, str);
    }
    ~Str(){
        delete[] data;
    }
    const char* c_str() const{
        return data;
    }
    Str(const Str& other):
    data(new char[strlen(other.data) + 1]{}){
        strcpy(data, other.data);
    }
    Str& operator=(const Str& other){
        if (this != &other){
            delete[] data;
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        return *this;
    }
    int length() const{
        return strlen(data);
    }

    static int cmp(const Str& str1, const Str& str2){
        return strcmp(str1.data, str2.data);
    }
    int cmp(const Str& other)
    {
        return cmp(*this, other);
    }


    
    static Str cat(const Str &str1, const Str &str2)
    {
        char* newData = new char[str1.length() + str2.length() + 1];
        strcpy(newData, str1.data);
        strcat(newData, str2.data);
        Str result;
        result.data = newData;
        return result;
    }
    Str cat(const Str &other) const
    {
        return Str::cat(*this, other);
    }
};

int main()
{
    Str str1("Hello"), str2("World");

    std::cout << str1.c_str() << " " << str2.c_str() << std::endl; // Hello World

    std::cout << Str::cat(str1, str2).c_str() << std::endl; // HelloWorld

    std::cout << Str::cmp(str1, str2) << std::endl; // <0

    str1 = str1.cat(str2);
    std::cout << str1.c_str() << std::endl; // HelloWorld

    std::cout << str1.cmp(str2) << std::endl; // <0

    return 0;
}