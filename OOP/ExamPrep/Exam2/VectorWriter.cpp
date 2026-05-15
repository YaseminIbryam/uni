#include <iostream>
#include <vector>
template<typename T>
class VectorWriter {
private:
std::vector<T> vec;
size_t index;
public:
VectorWriter(std::vector<T> vec) : vec(vec), index(vec.size()) {}
VectorWriter& operator<<(const T& el) {
    vec.insert(vec.begin() + index++, el);
    return *this;
}
void seek(std::size_t n) {
    if (n <= vec.size()) {
        index = n;
    }
}
VectorWriter &operator<<(const std::vector<T>& vect) {
    vec.insert(vec.begin() + index, vect.begin(), vect.end());
    index += vect.size();
    return *this;
}


std::vector<T> contents() const
{
    return vec;
}
};