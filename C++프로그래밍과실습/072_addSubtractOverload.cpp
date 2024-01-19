#include <iostream>

// complex.h
class Complex {
public:
    Complex(double real=0, double imaginary=0) : r(real), i(imaginary) {};
    Complex operator + (const Complex rhs);
    Complex operator - (const Complex rhs);
    friend std::ostream& operator << (std::ostream& os, const Complex& c);
private:
    double r{0}, i{0};
};

std::ostream& operator << (std::ostream& os, const Complex& c);

// complex.cpp
Complex Complex::operator + (const Complex rhs){
    return Complex{r + rhs.r, i + rhs.i};
}
Complex Complex::operator - (const Complex rhs){
    return Complex{r - rhs.r, i - rhs.i};
}
std::ostream& operator << (std::ostream& os, const Complex& c){
    return os << c.r << "+" << c.i << "i";
}

// main.cpp
int main() {
    Complex c1(3, 2);
    Complex c2(1, 1);

    std::cout << c1 + c2 << std::endl;
    std::cout << c1 - c2 << std::endl;

    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
}
