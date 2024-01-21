#include <cmath> // sqrt() 쓰기 위해 필요
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

template <typename T, size_t N>
auto myFind(array<T, N>& arr, T target){
    return find(arr.begin(),arr.end(), target);
}

class Complex{
    double r, i ;

public:
    Complex(double r=0, double i=0): r(r), i(i) { }

    bool operator<(const Complex& other) const{
        return size() < other.size() ;
    }

    bool operator==(const Complex& other) const{
        return r == other.r and i == other.i; // C++에서는 `&&` 대신 `and` 사용가능 // `||` 대신 `or` 도 사용가능`
    }

    double size() const{
        return sqrt(r*r + i*i);
    }

    friend ostream& operator<<(ostream& os, const Complex& c);
};

ostream& operator<<(ostream& os, const Complex& c){
    return os << c.r << " + " << c.i << "i";
}
