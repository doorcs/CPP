#include <cstddef>
#include <complex>
#include <vector>
#include <algorithm>
#include <iostream>

// implement the members
template <typename T, size_t N>
class MyList {
    T* _data = nullptr;
    int pos = 0;

public:
    MyList();
    MyList(const MyList& rhs) noexcept;

    ~MyList() noexcept;

    void add(T& data);
    void remove(T& data);

    T* begin();
    T* end();

    MyList& operator=(const MyList& other);
};
