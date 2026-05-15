#include <iostream>
#include <vector>

template<typename T> 
class VectorStream {
private:
std::vector<T> vec;
size_t index;
public:
VectorStream(std::vector<T> vec) : vec(vec), index(0) {}
VectorStream<T>& operator>>(T& var) {
    if(vec.empty()) {
        return *this;
    }
    var = vec[index];
    if (index < vec.size() - 1) {
        ++index;
    }
    *this >> var;
    return *this;
}
void reset() {
    index = 0;
}
T peek() const{
    if (vec.empty()) {
        return T();
    }
    return vec[index];
}


};



