#include <iostream>
#include <cstring>

class Student{
private:
    char* name;
    int course = 1;
    int fn;
    double averageGrade = 2.0;
public:
    Student(char* name, int course, int fn, double averageGrade):
        name(new char[strlen(name) + 1]{}),
        course(course),
        fn(fn),
        averageGrade(averageGrade){
            strcpy(this->name, name);
        }
    ~Student()
    {
        delete[] name;
    }

    Student(const Student& other):
        name(new char[strlen(other.name) + 1]{}),
        course(other.course),
        fn(other.fn),
        averageGrade(other.averageGrade){
            strcpy(this->name, other.name);
        }
    bool isPassing()
    {
        return averageGrade >= 3;
    }

};