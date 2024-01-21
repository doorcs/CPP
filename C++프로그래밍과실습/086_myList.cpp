#include "086_myList.h"

template <typename T, size_t N>
MyList<T, N>::MyList(): _data(new T[N]) { }

template <typename T, size_t N>
MyList<T, N>::MyList(const MyList<T, N>& other) noexcept{
    _data = new T[N];
    pos = other.pos;
    copy(other._data, other._data + pos, _data);
}

template <typename T, size_t N>
MyList<T, N>::~MyList() noexcept{
    delete[] _data;
}

template <typename T, size_t N>
void MyList<T, N>::add(T& data) {
    _data[pos] = data;
    pos++;
}

template<typename T, size_t N>
void MyList<T,N>::remove(T& data) {
    for(int i = 0; i < pos; i++) {
        if(_data[i] == data) {
            for(int j = i; j < N - 1; j++) {
                _data[j] = _data[j + 1];
            }
            --pos;
            break;
        }
    }
}

template <typename T, size_t N>
T* MyList<T, N>::begin(){ return _data; }

template <typename T, size_t N>
T* MyList<T, N>::end(){ return _data + N; }

template <typename T, size_t N>
MyList<T, N>& MyList<T, N>::operator=(const MyList<T, N>& other){
    if(this != &other){
        delete[] _data;
        _data = new T[N];
        pos = other.pos;
        copy(other._data, other._data + pos, _data);
    }
    return *this;
}
