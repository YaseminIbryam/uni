#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;


enum class AttackType
{
    PHYSICAL,
    FIRE,
    WATER,
    LIGHTNINg,
    HOLY,
};

class Character {
protected:
    int HP;
    int attackPower;
public:
    Character(int HP = 0, int attackPower = 0) : HP(HP), attackPower(attackPower) {}

    virtual ~Character() {}

    virtual Character* clone() const = 0;

    virtual void takeDamage(int power, AttackType type) {
        HP -= power;
    };

    bool isAlive() {
        return HP > 0;
    }

    virtual void attack(Character *other) = 0;

};

class Zombie : public Character {
public:
    Zombie(int attackPower = 4) : Character(20, attackPower) {}

    Character* clone() const final {
        return new Zombie(*this);
    }
    void takeDamage(int power, AttackType type) final {
        if (type == AttackType::FIRE) {
            HP -= 2*power;
        }
        else
        {
            Character::takeDamage(power, type);
        }
    }

    void attack(Character *other) final {
        other->takeDamage(attackPower, AttackType::PHYSICAL);
    }
private:
};

class Player : public Character {
private:
    int hearts = 3;
public:
    Player(int attackPower = 10) : Character(50, attackPower) {}

    Character* clone() const final {
        return new Player(*this);
    }
    void takeDamage(int power, AttackType type) final {
        Character::takeDamage(power, type);
        if (HP <= 0 && hearts > 0) {
            hearts--;
            HP = 50;
        }
    }
    

    void attack(Character *other) final{
        int randomNum = rand() % 5;
        AttackType randomType = static_cast<AttackType>(randomNum);
        other->takeDamage(attackPower, randomType);
    }
};

class FireElemental : public Character {
public:
    FireElemental(int attackPower = 6) : Character(30, attackPower){}
    Character* clone() const final {
        return new FireElemental(*this);
    }
    void takeDamage(int power, AttackType type) final{
        if (type == AttackType::WATER) {
            HP -= 2 * power;
        }
        else if (type == AttackType::FIRE){
            HP += power / 2;
        }
        else
        {
            Character::takeDamage(power, type);
        }
    }
    void attack(Character *other) final {
        other->takeDamage(attackPower, AttackType::FIRE);
    }
};

class Goomba : public Character {
public:
    Goomba() : Character(1, 0) {}
    Character *clone() const final
    {
        return new Goomba(*this);
    }
    void takeDamage(int power, AttackType type) final {
        HP = 0;
    }

    void attack(Character *other) final{}

};

int main() {
    srand(time(0));

    // Създаваме героя
    Character *hero = new Player(15);

    // Създаваме вектор от врагове (нашата "орда")
    vector<Character *> enemies;
    enemies.push_back(new Zombie(10));
    enemies.push_back(new FireElemental(12));
    enemies.push_back(new Goomba());

    cout << "=== BITKATA ZAPOCHVA! ===" << '\n';

    int round = 1;
    // GAME LOOP: Играта продължава, докато героят е жив И има живи врагове
    while (hero->isAlive() && !enemies.empty())
    {
        cout << "\n--- RUND " << round << " ---" << '\n';

        // 1. Ход на ИГРАЧА
        // Винаги атакуваме първия враг в редицата
        Character *target = enemies[0];
        cout << "Geroqt atakuva vrag nomer 1!" << '\n';
        hero->attack(target);

        // Проверяваме дали сме убили врага с тази атака
        if (!target->isAlive())
        {
            cout << "Vragat e pobeden!" << '\n';
            delete target;                  // Освобождаваме паметта на мъртвия враг
            enemies.erase(enemies.begin()); // Премахваме го от вектора
        }

        // 2. Ход на ВРАГОВЕТЕ
        // Всеки оцелял враг във вектора атакува героя
        for (size_t i = 0; i < enemies.size(); i++)
        {
            // Проверяваме дали героят не е умрял междувременно от предишен удар
            if (hero->isAlive())
            {
                enemies[i]->attack(hero);
            }
        }

        round++;
    }

    // --- КРАЙ НА ИГРАТА ---
    cout << "\n=== KRAI NA IGRATA ===" << '\n';
    if (hero->isAlive())
    {
        cout << "POBEDA! Geroqt unishtoji vsichki vragove!" << '\n';
    }
    else
    {
        cout << "ZAGUBA... Geroqt padna v bitka." << '\n';
    }

    // Почистване на паметта (ако героят е умрял, враговете може да са останали живи във вектора)
    delete hero;
    for (size_t i = 0; i < enemies.size(); i++)
    {
        delete enemies[i];
    }
}