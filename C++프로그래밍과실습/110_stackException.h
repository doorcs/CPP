#include <stdexcept> // runtime_error
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class StackException: public runtime_error{
    string msg;
    string file;
    size_t line;

public:
    StackException(string msg, string file, size_t line): runtime_error(msg), file(file), line(line){
        ostringstream os;
        os << file << ':' << line  << ':' << "Exception: " << msg << endl;
        this->msg = os.str();
    }

    ~StackException() noexcept{ }

    const char* what() const noexcept final{ // 상속받은`.what()` 반환타입은 const char* (C-style string)
        return msg.c_str();
    }
};

template <typename T>
class Stack {
    T* data = nullptr;
    size_t size = 0;
    size_t top = 0;

public:
    Stack(int size);
    ~Stack() noexcept;

    // 첫번째 선언에서만 함수를 `=delete`로 삭제할 수 있기 때문에 이부분은 선언과 정의를 분리할 수 없다!
    Stack(const Stack& other) = delete; // 복사 생성자 삭제
    Stack& operator=(const Stack& other) = delete; // 복사 대입 생성자 삭제

    void push(const T& elem);
    T& pop();

    void print() const;
} ;

template <typename T>
Stack<T>::Stack(int size): size(size), data(new T[size]) { }

template <typename T>
Stack<T>::~Stack() noexcept{
    delete[] data;
}

template <typename T>
void Stack<T>::push(const T& elem){
    if(top < size) data[top++] = elem;

    else throw StackException("Stack is full!",__FILE__, __LINE__);
}

template <typename T>
T& Stack<T>::pop(){
    if(top != 0) return data[--top];

    else throw StackException("Stack is empty!", __FILE__, __LINE__);
}

template <typename T>
void Stack<T>::print() const{
    for(int i=0; i<top; i++) cout << data[i] << '\n';
}
