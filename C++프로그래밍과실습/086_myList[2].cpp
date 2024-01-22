#include "086_myList[2].h"

template <typename T, size_t N>
MyList<T, N>::MyList(){ // 다른 멤버들과의 일관성을 위해 초기화 리스트를 사용하지 않고 구현
    data = new T[N];
}

template <typename T, size_t N>
MyList<T, N>::MyList(const MyList<T, N>& other) noexcept{ // 복사 생성자
    data = new T[N];
    pos = other.pos;
    copy(other.data, other.data + pos, data);
}

template <typename T, size_t N>
MyList<T, N>::~MyList() noexcept{ // 소멸자는 꼭 noexcept 붙여주기
    delete[] data;
}

template <typename T, size_t N>
void MyList<T, N>::add(T& elem){
    data[pos++] = elem; // data[pos] = elem; 수행 후 pos += 1;
}

template<typename T, size_t N>
void MyList<T,N>::remove(T& elem){ // 배열의 삽입과 삭제는 O(N)의 시간복잡도를 가진다
    for(int i = 0; i < pos; i++){
        if(data[i] == elem){
            for(int j = i; j < N - 1; j++) data[j] = data[j + 1];
            pos--;
            break; // 여러 개 있는 경우에는 모두 삭제하는게 아니라 처음 만난 하나만 삭제한다!!!!!!!!!!!!!!!!!!!!!!!!!!
        }
    }
}

template <typename T, size_t N>
T* MyList<T, N>::begin(){ return data; } // 이터레이터는 일반화된 포인터

template <typename T, size_t N>
T* MyList<T, N>::end(){ return data + N; } // 이터레이터 == 컨테이너의 특정 지점을 가리키는 `포인터를 반환하는 멤버함수(메소드)`

template <typename T, size_t N>
MyList<T, N>& MyList<T, N>::operator=(const MyList<T, N>& other){ // 복사 대입 생성자
    if(this != &other){ // 자기대입 체크
        pos = other.pos;

        delete[] data;
        data = new T[N];
        copy(other.data, other.data + pos, data);
    }
    return *this; // this는 객체 자신을 가리키는 포인터. 따라서 `*this`로 this를 참조하면 객체 자신!
}
