// Задача 2. (60 г.) Да се дефинира шаблон на клас BoundSet<T> описващ множество от елементи от произволен тип Т, което може да има не повече от № елемента.
// Максималният брой елементи в множеството се задава в конструктора му и не се променя по време на изпълнение. За класа да се реализират
// 20 т. оператории + и +=, обединяващи две множества. Размерът на множество, получено чрез оператор + да е достатъчен, за да събере всички елеме изходните множества. Оператор += да не изменя капацитета на множеството
// 10 т. (методи add, remove и member за добавяне, премахване и проверка дали даден елемент е член на множеството
// 30 т. необходимите контруктори, оператори и деструктори за коректно управление на динамичната памет

#include <iostream>

template <typename T>
void copy(T *el1, const T *el2, int size)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        el1[i] = el2[i];
    }
}

template<typename T>
class BoundSet{
private:
    T* set;
    int capacity;
    int size;
public:
    BoundSet(const T* set, const int N, int size)
        : set(new T[N]),
        capacity(N),
        size(0) {
        for(std::size_t i = 0; i < size; ++i){
            add(set[i]);
        }
    }
    BoundSet(const int N) 
        : set(new T[N]),
        capacity(N),
        size(0) {}
    ~BoundSet(){
        delete[] set;
    }
    BoundSet(const BoundSet& other)
        : set(new T[other.capacity]),
        size(other.size) ,
        capacity(other.capacity){
        copy(this->set, other.set, other.size);
    }
    BoundSet& operator=(const BoundSet& other){
        if(this != &other) {
            delete[] set;
            set = new T[other.capacity];
            copy(this->set, other.set, other.size);
            size = other.size;
            capacity = other.capacity;
        }
        return *this;
    }
    void add(const T el){
        if (size + 1 <= capacity && !member(el))
            set[size++] = el;
    }
    bool member(const T el) const {
        for (std::size_t i = 0; i < size; ++i) {
            if (set[i] == el)
                return true;
        }
        return false;
    }
    void remove(const T el) {
        if (member(el)){
            std::size_t i = 0;
            while (i < size && set[i] != el) {
                i++;
            }
            if (set[i] == el) {
                for(std::size_t j = i; j < size -  1; ++j) {
                    set[j] = set[j + 1];
                }
            }
            size--;
        }

    }
    BoundSet operator+(const BoundSet& other) const {
        BoundSet result(this->size + other.size);
        for(std::size_t i = 0; i < this->size; ++i){
            result.add(this->set[i]);
        }
        for (std::size_t i = 0; i < other.size; ++i)
        {
            result.add(other.set[i]);
        }
        return result;
    }
    BoundSet& operator+=(const BoundSet& other) {
        for(std::size_t i = 0; i < other.size; ++i){
            add(other.set[i]);
        }
        return *this;
    }
    const T& operator[](const int i) const {
        return set[i];
    }
    bool operator==(const BoundSet& other) const {
        if (size != other.size)
            return false;
        std::size_t i = 0;
        while(i < size) {
            if (set[i] != other.set[i]) {
                return false;
            }
            i++;
        }
        return true;
    }
    friend std::ostream& operator<<(std::ostream& os, const BoundSet& obj) {
        for(int i = 0; i < obj.size; i ++) {
            os << obj.set[i] < " ";
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& i, BoundSet obj) {
        i >> obj.set;
        return i;
    }
        

};

