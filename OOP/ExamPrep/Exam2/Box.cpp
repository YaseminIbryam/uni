#include <iostream>
#include <vector>

template<typename T>
class Box {
private:
std::vector<T> items;
public:
Box(const std::vector<T>& items) : items(items) {}
Box(const Box& other) : items(other.items) {}
Box& operator+=(const T& item) {
    items.push_back(item)
    return *this;
}

Box operator+(const Box& other) const {
    Box copy(*this);
    copy.items.insert(copy.items.begin(), other.items.begin(), other.items.end())
    return copy;
}
};