#include <cstddef>
#include <complex>
#include <vector>
#include <algorithm>
#include <iostream>

template <typename T, size_t N> // Non-type 파라미터 N을 함께 받는다
class MyList {
    T* data = nullptr;
    int pos = 0;

public:
    MyList();
    MyList(const MyList& other) noexcept;

    ~MyList() noexcept;

    void add(T& elem);
    void remove(T& elem);

    T* begin();
    T* end();

    MyList& operator=(const MyList& other);
};
