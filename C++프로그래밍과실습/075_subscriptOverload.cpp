// Array.h
#include <cstddef>
#include <initializer_list>
#include <memory>

class Array {
public:
    Array(std::initializer_list<int> args, size_t size);
    int& operator [] (int index);
    size_t size() const;

private:
    std::unique_ptr<int[]> data;
    size_t _size;
};
// Array.cpp
// #include "Array.h"
#include <iostream>
using namespace std;

Array::Array(std::initializer_list<int> args, size_t size): data(new int[size]), _size(size) {
    copy(args.begin(), args.end(), data.get());
}

int& Array::operator [](int index){
    return data[index];
}

size_t Array::size() const{
    return _size;
}

// main.cpp
// #include "Array.h"

int main(){
    Array myArr {{1, 2, 3, 4}, 4};
    for (int i = 0; i < myArr.size(); ++i)
        std::cout << myArr[i] <<std::endl;
}
