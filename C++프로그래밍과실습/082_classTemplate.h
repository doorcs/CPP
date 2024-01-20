#include <algorithm>
#include <initializer_list>
#include <memory>
using namespace std;

template<typename T>
class my_vector {
public:
    explicit my_vector(size_t N=0) noexcept ;  // 생성자를 구현하시오

    my_vector(std::initializer_list<int> lst) noexcept ;  // 생성자를 구현하시오

    my_vector(const my_vector<T>& other) noexcept ; // 복사 생성자를 구현하시오 (deep copy)

    T& operator[](int i) ; // subscript operator `[]`를 오버로딩하시오

    size_t size() const; // 멤버 함수를 구현하시오
private:
    size_t _size;
    std::unique_ptr<T[]> _data;
};

//template<typename T> // 테케에서 기본 생성자는 활용하지 않음
//my_vector<T>::my_vector(size_t N) noexcept: _size(N), _data(new T[N]) { }

template<typename T>
my_vector<T>::my_vector(std::initializer_list<int> lst) noexcept: _size(lst.size()), _data(new T[lst.size()]){
    copy(lst.begin(), lst.end(), _data.get());
}

template<typename T>
my_vector<T>::my_vector(const my_vector<T>& other) noexcept{
    _data.reset(new T[other._size]);
    _size = other._size;
    for(int i=0; i<_size; i++) _data[i] = other._data[i];
}

template <typename T>
T& my_vector<T>::operator[](int i){
    return _data[i];
}

template <typename T>
size_t my_vector<T>::size() const{
    return _size;
}
