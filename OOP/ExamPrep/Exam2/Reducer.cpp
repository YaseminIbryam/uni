#include <iostream>
#include <vector>
#include <functional>
class Reducer {
protected:
std::vector<double> seq;
public:
Reducer() = default;
void add(double el) {
    seq.push_back(el);
}
virtual double compute() const = 0;
virtual  ~Reducer() = default;
};

class Product : public Reducer {
public:
Product() = default; //или Product() : Reducer() {}??
double compute() const {
    if(seq.empty()) {
        return 1;
    }
    double res = 1;
    for (double el : seq) {
        res *= el;
    }
    return res;
}
};

class CountAbove : public Reducer{
private:
double threshold;
public: 
CountAbove(double threshold) : threshold(threshold) {}

double compute() const {
    if(seq.empty()) {
        return 0;
    }
    size_t count = 0;
    for (double el : seq) {
        if (el - threshold > 0 ) { //помня че имаше осоеност с double ама не помня каква и това е същото като el > threshold ама това беше май за равно???
            ++count;
        }
    }
    return count;
}
};

class Accumulator : public Reducer {
private:
std::function<double(double a, double b)> func;
double null_value;
public:
Accumulator(std::function<double(double a, double b)> func, double null_value) : func(func), null_value(null_value) {}
double compute() const {
    double result = null_value;
    for (double el : seq) {
        result = func(result, el);
    }
    return result;
}


};

double process(const std::vector<double>& data, Reducer* comb) {
    for (double el : data) {
        comb->add(el);
    }
    return comb->compute();
}