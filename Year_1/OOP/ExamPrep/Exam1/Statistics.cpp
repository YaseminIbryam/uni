// Условия на задачите за контролно 
// 1 Задача 1. [40 т.] Да се реализира клас Statistics, който представя обобщена информация за поредица от цели числа.При създаване на обект от класа, съответната му поредица се счита за празна.[15 τ.] 
// add, добавя число към поредицата
// [x 2 τ.] num, който връща броя на числата, добавени в поредицата 
// sum, който връща сумата на поредицата(или О за празна редица) 
// prod, който връща произведението на числата в поредицата(или 1 за празна редица)
// mах, който връща максималното число от поредицата(за празна поредица може да връща произволна стойност) 
// average, който връща средното аритметично на числата в поредицата
// [15 τ.] оператори + и += за добавяне на число към редицата 
// Функционалност извън тези методи, като например съхраняване на отделните числа от поредицата, не е необходима.Пример : Statistics seq1;
// seq1 += 10;
// seq1 += 5;
// cout << seq1.sum(); //->15 (10+5)

#include <iostream>

class Statistics{
private:
    int _num;
    int _sum;
    int _prod;
    int _max;

public:
    Statistics()
        : _num(0),
        _sum(0),
        _prod(1),
        _max(0){};

    void add(const int number){
        _num++;
        _sum += number;
        _prod *= number;
        if (_num == 1 || _max < number) {
            _max = number;
        }
    }
    double average(){
        if (_num == 0){
            return 0;
        }
        return (double) _sum / _num;
    }
    Statistics operator+(const int number){
        Statistics copy = *this;
        copy.add(number);
        return copy;
    }
    Statistics& operator+=(const int number)
    {
        this->add(number);
        return *this;
    }
    int sum() const {
        return _sum;
    }
    int num() const {
        return _num;
    }
    int prod() const {
        return _prod;
    }
    int max() const {
        return _max;
    }
};

int main(){
    Statistics seq1;
    seq1 += 10;
    seq1 += 5;
    std::cout << seq1.sum();
}