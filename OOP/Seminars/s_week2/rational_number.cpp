#include <iostream>
class Rational
{
public:
    Rational(int numerator, int denominator) : numerator(numerator), denominator(1)
    {
        set_denominator(denominator);
    }

    int get_numerator()
    {
        return numerator;
    }

    int get_denominator()
    {
        return denominator;
    }

    void set_numerator(int n)
    {
        numerator = n;
    }

    void set_denominator(int n)
    {
        if (n != 0)
        {
            denominator = n;
        }
    }

    void simlpify() {
        int max = numerator > denominator ? numerator:denominator;
        int min = numerator + denominator - max;
        while (min != 0){
            int res = max % min;
            max = min;
            min = res;
        }
        int gcd = max;
        set_numerator(numerator/gcd);
        set_denominator(denominator/gcd);
        
    }
    void plus(Rational other)
    {
        if(other.denominator == denominator)
        {
            numerator += other.numerator;
        }
        else
        {
            numerator = numerator * other.denominator + other.numerator * denominator;
            denominator *= other.denominator;
        }
        simlpify();

    }
    void multiply(Rational other)
    {
        denominator *= other.denominator;
        numerator *= other.numerator;
    }
    int compare(Rational other)
    {
        double res1 = double(other.numerator)/ double(other.denominator);
        double res2 = double(numerator) / double(denominator);
        if (res1 < res2)
            return 1;
        else if (res1 > res2)
        {
            return -1;
        }
        else 
        {
            return 0;
        }
        

    }

    private : int numerator;
    int denominator;
};

int main()
{
    // 1. Създаваме две дроби: 1/2 и 1/3
    Rational r1(1, 2);
    Rational r2(1, 3);

    std::cout << "Zapoqvame s r1 = " << r1.get_numerator() << "/" << r1.get_denominator() << "\n";
    std::cout << "Zapoqvame s r2 = " << r2.get_numerator() << "/" << r2.get_denominator() << "\n\n";

    // 2. Тестваме сравняването (1/2 е по-голямо от 1/3, значи трябва да върне 1)
    int compResult = r1.compare(r2);
    std::cout << "Sravnenie (r1 sprqmo r2): " << compResult << " (Ochakvame 1)\n\n";

    // 3. Тестваме събирането (1/2 + 1/3 = 5/6)
    r1.plus(r2);
    std::cout << "Sled r1.plus(r2), r1 stava: "
              << r1.get_numerator() << "/" << r1.get_denominator() << " (Ochakvame 5/6)\n\n";

    // 4. Тестваме умножението (текущото r1 вече е 5/6. Умножаваме 5/6 * 1/3 = 5/18)
    r1.multiply(r2);
    std::cout << "Sled r1.multiply(r2), r1 stava: "
              << r1.get_numerator() << "/" << r1.get_denominator() << " (Ochakvame 5/18)\n";

    // 5. Тестваме твоето велико съкращаване!
    Rational r3(10, 20); // 10/20
    r3.simlpify();
    std::cout << "\nTest za sukrashtavane na 10/20 -> "
              << r3.get_numerator() << "/" << r3.get_denominator() << " (Ochakvame 1/2)\n";

    return 0;
}
