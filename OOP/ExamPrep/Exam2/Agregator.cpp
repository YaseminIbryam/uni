#include <iostream>
#include <vector>
#include <functional>
class Agregator {
protected:
std::vector<double> seq;
double findSum() const{
    double sum = 0;
    for(double num : seq) {
        sum += num;
    }
    return sum;
}
public:
Agregator() = default; 
void add(double num) {
    seq.push_back(num);
}
virtual double result() const = 0;

virtual ~Agregator() = default;

};

class Sum : public Agregator {
public:
Sum() = default;
double result() const final{
    return findSum();
}
};

class Avg : public Agregator
{
public:
Avg() = default;
double result() const final{
    return findSum() / seq.size();
};
};


class Foldr : public Agregator
{
private:
std::function<double(double, double)> func;
public:

Foldr() = default;
Foldr(std::function<double(double, double)> func) : func(func) {}

double result() const final{
    if (seq.empty())
    {
        return 0.0;
    }
    double res = seq[0];
    for (std::size_t i = 1; i < seq.size(); ++i)
    {
        res = func(res, seq[i]);
    }
    return res;
}
};

double reduce(const std::vector<double>& seq, Agregator* agg) {
    for(double el : seq) {
        agg->add(el);
    }
    return agg->result();
}

