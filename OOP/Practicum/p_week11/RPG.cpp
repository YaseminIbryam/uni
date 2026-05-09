#include <iostream>
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
public:
    Character(int HP = 0) : HP(HP) {}

    virtual ~Character() {}

    virtual void takeDamage(int power, AttackType type) = 0;

    bool isAlive() {
        return HP > 0;
    }

    virtual void attack(Character *other) = 0;

};