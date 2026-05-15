 //1. Абстрактен базов клас (Основата)
// Това е класът, от който другите ще наследяват. Ако имаш виртуални функции, задължително ти трябват виртуален деструктор и clone().
#include <iostream>
class Enemy {
protected:
    int hp;
public:
    Enemy(int hp) : hp(hp) {}

    // 1. ЗАДЪЛЖИТЕЛЕН виртуален деструктор!
    virtual ~Enemy() = default; 

    // 2. ЗАДЪЛЖИТЕЛЕН виртуален копиращ конструктор!
    virtual Enemy* clone() const = 0; 
    
    // 3. Някаква друга виртуална функция
    virtual void attack() const = 0; 
};
// 2. Клас Наследник (Детето)
// Тук трябва да реализираш clone(), за да може обектът да копира самия себе си.

class Zombie : public Enemy {
private:
    int damage;
public:
    Zombie(int hp, int dmg) : Enemy(hp), damage(dmg) {}

    // Имплементация на clone() - винаги изглежда точно така:
    Enemy* clone() const override {
        return new Zombie(*this); // Извиква собствения си копиращ конструктор
    }

    void attack() const override {
        // Логика за атака...
    }
};
// 3. Голямата четворка с char* (Copy-and-Swap идиом)
// Ако имаш клас, който държи текст (char*) или динамичен масив (int*), това е най-сигурният начин да напишеш Голямата четворка, без да гръмне паметта.


#include <cstring>

class Player {
private:
    char* name;

public:
    // Помощна функция за размяна (БЕЗ const в параметъра!)
    void swap(Player& other) {
        std::swap(name, other.name);
    }

    // 1. Конструктор (ВНИМАНИЕ: + 1 за strlen!)
    Player(const char* initName = "Unknown") {
        name = new char[strlen(initName) + 1];
        strcpy(name, initName);
    }

    // 2. Деструктор
    ~Player() {
        delete[] name;
    }

    // 3. Копиращ конструктор
    Player(const Player& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    // 4. Оператор = (Copy-and-Swap)
    Player& operator=(const Player& other) {
        Player copy(other); // Правим локално копие
        swap(copy);         // Разменяме нашите данни с копието
        return *this;       // Копието умира и трие старите ни данни
    }
};
// 4. Клас Мениджър (Вектор от указатели)
// Това е класът (като Game, City, ShoppingCart), който събира различни наследници на едно място. Щом има вектор от указатели, трябва да му напишеш Голяма четворка, въпреки че е вектор!

#include <vector>

class Game {
private:
    std::vector<Enemy*> enemies;

public:
    Game() = default;

    // 1. Деструктор (Трябва да изтрие самите обекти, не само вектора!)
    ~Game() {
        for (Enemy* e : enemies) {
            delete e; 
        }
        // Векторът сам ще се изчисти след това
    }

    // 2. Копиращ конструктор (Тук ползваме clone!)
    Game(const Game& other) {
        for (Enemy* e : other.enemies) {
            this->enemies.push_back(e->clone()); // Дълбоко копие!
        }
    }

    // 3. Помощна функция за swap
    void swap(Game& other) {
        std::swap(enemies, other.enemies); // Векторите имат вграден бърз swap
    }

    // 4. Оператор = (Copy-and-Swap)
    Game& operator=(const Game& other) {
        Game copy(other);
        swap(copy);
        return *this;
    }

    // Метод за добавяне с копиране (защитава данните)
    void addEnemy(const Enemy& newEnemy) {
        enemies.push_back(newEnemy.clone());
    }
};

// Имам ли virtual пред деструктора в базовия клас? (Ако не -> memory leak при триене на полиморфен обект).

// Сложих ли + 1 на всеки new char[strlen(text) + 1]? (Ако не -> undefined behavior/краш).

// Имат ли всички get методи, оператори == и print функции const накрая? (Пример: int getHp() const;).

// Когато подавам обект на конструктор или функция, ползвам ли const Type&? (Пример: void print(const Player& p) вместо void print(Player p)).

// Написах ли delete[] за масиви и само delete за единични обекти?