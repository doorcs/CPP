#include <initializer_list>
#include <iostream>
using namespace std;

class matrix{
public:
    // 생성자, 복사 생성자
    // 연산자 오버로딩
    // 멤버 함수들
    matrix(initializer_list<initializer_list<int>> values);
    matrix(const matrix& other);
    ~matrix() noexcept;

    matrix& operator+(const matrix& other);
    matrix& operator=(const matrix& other);

    matrix& inverse();
    friend ostream& operator<<(ostream& os, const matrix& m);
private:
    int* data = nullptr;
    size_t row = 0;
    size_t col = 0;
};
ostream& operator<<(ostream& os, const matrix& m);
