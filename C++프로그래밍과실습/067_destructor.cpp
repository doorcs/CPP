#include "067_destructor.h"

String::String() { // 기본(empty) 생성자
    s = new char[1];
    s[0] = '\0';
    len = 0;
}
String::String(const char* str) { // 생성자 w/ C-style string
    len = 0;
    while(str[len] != '\0') len++;

    if(str) {
        s = new char[len + 1];
        copy(str, str+len+1, s);
    } else {
        s = new char[1];
        s[0] = '\0';
    }
}

String::String(const String& str) { // 복사 생성자
    len = str.len;
    s = new char[len + 1];
    copy(str.s, str.s+len+1, s);
}

String::~String() noexcept{ // 소멸자
    delete[] s;
    cout << "Destructor" << endl;
}

String& String::operator=(const String& str){ // 복사 대입 생성자
    if (this != &str) { // 자기 대입(self assignment) 처리 << 중요!!!!
            len = str.len;
            delete[] s; // empty 체크는 필요없는데, nullptr에 대한 `delete`나 `delete[]`는 안전하기 때문!!
            // 단, 초기화되지 않은 포인터나 이미 해제된 포인터에 대한 delete는 UB(Undefined Behavior, *예측할 수 없음* ).
            // 또, `delete` 와 `delete[]` 는 반드시 구분해야 함!

            s = new char[len + 1];
            copy(str.s, str.s+len+1, s);
    }
    return *this;
}

const char* String::data() const{
    return s;
}

char& String::at(size_t idx){
    return s[idx];
}

size_t String::size() const{
    return len;
}

void String::print(const char* str) const{
    cout << str << ": " << s << ", size: " << len << endl;
}

void String::swap(String& str){
    // std::swap(s, str.s);
    // std::swap(len, str.len);
    ; // swap은 구현하지 않아도 프로그램 수행에 문제 X
}
