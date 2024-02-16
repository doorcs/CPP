#include <vector>
using namespace std;

size_t SIZE = 10;

// 설명의 편의상 int를 담는 벡터만 사용

int main() {
//  가장 일반적인 1차원 벡터 선언(빈 벡터, 크기가 0인 벡터를 만든다!):
    vector<int> v1;

//  vector<int> v1{}; 처럼 선언할 수도 있다(빈 initializer_list를 넘겨주기 때문에 결과적으로는 빈 벡터를 만듦)

//  하지만 vector<int> v1(); 처럼은 사용할 수 없다. 왜?
//  vector<int> func1(); // 이런식으로 리턴 타입이 `vector<int>`인 함수의 선언부라고 인식하기 때문!!!(v1을 func1로 바꾸면 위 코드와 완전히 똑같다) 컴파일러에게 혼동을 줄 여지가 있다


//  크기를 0이 아닌 값으로 초기화하고 싶을 경우(이 경우에도 추후에 크기를 변경할 수 있다):
    vector<int> v2(SIZE);

//  이렇게 해두면
//  for(size_t i=0; i<SIZE; i++) cin >> v2[i]; 같은 코드를 쓸 수 있다

//  선언과 동시에 원소를 채우며 초기화 w/ initializer_list (C++11):
    vector<int> v3{6, 7, 8, 9};

//  복사 대입 생성자를 사용(오버로딩된 operator=)
    vector<int> v4 = v3;

//  복사 생성자를 사용
    vector<int> v5(v3);
}

    // 이런식으로 구현돼있지 않을까?
/*
    // 복사 대입 생성자(operator=)
    template <typename T>
    vector<T>& vector<T>::operator=(const vector<T>& rhs){
        if(this != &rhs){ // 자기대입 체크
            delete[] data; // 기존 data 해제

            this.capacity = rhs.capacity;
            this.data = new T[capacity];

            copy(rhs.data, rhs.data+capacity, this.data); // deep copy!
        }
        return *this;
    }

    // 복사 생성자
    template <typename T>
    vector<T>::vector(const vector<T>& rhs){
        this.capacity = rhs.capacity;
        this.data = new T[capacity];

        copy(rhs.data, rhs.data+capacity, this.data); // deep copy!!
    }
*/ 
