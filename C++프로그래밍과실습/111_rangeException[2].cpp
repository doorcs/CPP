// #include <cstddef> // redundant
#include <iostream>
#include <exception>
#include <string>
typedef unsigned long size_t;
using namespace std;

template <typename T>
class Array{
    T* data;
    size_t size;
public:
    Array(size_t size);
    ~Array() noexcept;

    T& at(size_t index);
};

template <typename T> // 클래스 템플릿 바깥에서 멤버를 정의할 땐 항상 `template <typename T>`를 붙여줘야한다...
Array<T>::Array(size_t size): size(size), data(new T[size]) { }

template <typename T> // 귀찮아요
Array<T>::~Array() noexcept{
    delete[] data;
}

template <typename T> // 귀찮아요
T& Array<T>::at(size_t index){
    if(index >= 0 && index < size) return data[index];
    throw out_of_range(to_string(index));
}

int main() {
    Array<int> arr(5);
    try {
        arr.at(0) = 1;
        arr.at(1) = 2;
        arr.at(2) = 3;
        arr.at(3) = 4;
        arr.at(4) = 5;
        arr.at(5) = 6;
    }
    catch (out_of_range e){
        cerr << "Out of Range error: " << e.what() << endl;
    }
}
