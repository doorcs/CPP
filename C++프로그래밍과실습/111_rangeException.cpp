#include <cstddef> // typedef unsigned long size_t
#include <iostream>
#include <exception>
#include <string>
using namespace std;

template <typename T>
class Array{
    T* data;
    size_t size;
public:
    Array(size_t size): size(size), data(new T[size]) { }

    T& at(size_t index){
        if(0 <= index && index < size) return data[index];
        throw out_of_range(to_string(index)); // 매개변수로 들어온 index가 if문에 걸리지 않으면 `std::out_of_range()`를 throw
    }
    ~Array() noexcept{
        delete[] data;
    }
};

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
    // 예외처리 코드 추가하기
    catch (out_of_range e){ // std::out_of_range 에러 객체를 catch
        cerr << "Out of Range error: " << e.what() << endl; // cerr은 character error의 약자 // cout은 character out의 약자
    }
}
