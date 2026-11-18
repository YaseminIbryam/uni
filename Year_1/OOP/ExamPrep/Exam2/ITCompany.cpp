#include <iostream>

class Employee {
public:
virtual void work() = 0;
virtual Employee* clone() const = 0;
virtual ~Employee() = default;
};

class Developer : public Employee {
public:
void work() final {
    std::cout << "Dev works";
}
Employee *clone() const final {
    return new Developer(*this);
}
class Manager : public Employee {
public:
void work() final {
    std::cout << "Manager works";
}
Employee *clone() const final {
    return new Manager(*this);
}

}