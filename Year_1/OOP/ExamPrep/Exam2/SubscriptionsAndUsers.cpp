// Част 1: Да се реализира клас Subscription, описващ абонамент.

// Член-данни: ID (цяло положително число), Платформа (символен низ с произволна дължина, заделен динамично) и Месечна такса (double).

// Методи:

// Голяма четворка за правилно управление на паметта.

// Оператор ==, който сравнява два абонамента само по тяхното ID.

// Оператор << за извеждане на информация за абонамента.

// Част 2: Да се реализира клас UserAccount, представляващ потребител.

// Член-данни: Динамичен масив от абонаменти и капацитет N (задава се при създаване на обекта и не се променя).

// Методи:

// Голяма четворка.

// addSubscription(const Subscription& sub): Добавя абонамент. Ако капацитетът е достигнат, игнорира опита. Методът трябва да позволява навързване (chaining) – напр. user.add(s1).add(s2);.

// totalMonthlyCost(): Връща общата сума на всички абонаменти.

// [БОНУС] filter: Метод, който приема предикат (указател към функция или std::function) и премахва от масива всички абонаменти, за които предикатът връща false (например: изтрий всички абонаменти с такса над 20 лв.).
#include <iostream>
#include <cstring>
class Subscription {
private:
int id;
char* platform;
double monthlyFee;

public:
void swap(Subscription& other) {
    std::swap(id, other.id);
    std::swap(platform, other.platform);
    std::swap(monthlyFee, other.monthlyFee);
}
Subscription(int id = 0,const char* platform = "", double mountlyFee = 0.0) 
: id(id), 
platform(new char[strlen(platform) + 1]), 
monthlyFee(monthlyFee) {
    strcpy(this->platform, platform);
}
~Subscription () {
    delete[] platform;
}

Subscription(const Subscription& other) {
    id = other.id;
    platform = new char[strlen(other.platform) + 1];
    strcpy(platform, other.platform);
    monthlyFee = other.monthlyFee;
}

Subscription &operator=(const Subscription& other) {
    Subscription copy(other);
    swap(copy);
    return *this;
}

bool operator==(const Subscription& other) const {
    return id == other.id;
}

friend std::ostream &operator<<(std::ostream &out, const Subscription &sub);

};

std::ostream &operator<<(std::ostream &out, const Subscription &sub) {

    out << "ID: " << sub.id << '\n';
    out << "Platform: " << sub.platform << '\n';
    out << "Monthly Fee: " << sub.monthlyFee << '\n';
    return out;
};

class UserAccount {
private:
Subscription* subs;
int capacity;
int size;
public:
    UserAccount(int N) : capacity(N), size(0) {
        subs = new Subscription[N];
    }

    ~UserAccount() {
        delete[] subs;
    }

    UserAccount(const UserAccount& other) {
        capacity = other.capacity;
        size = other.size;
        subs = new Subscription[size];
        for(int i = 0; i < size; i++) {
            subs[i] = other.subs[i];
        }
    }
    void swap(UserAccount& other) {
        std::swap(subs, other.subs);
        std::swap(capacity, other.capacity);
        std::swap(size, other.size);
    }

    UserAccount& operator=(const UserAccount& other) {
        UserAccount copy(other);
        swap(copy);
        return *this;
    }

    

};
