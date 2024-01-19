#include <algorithm>
#include <iostream>
#include <iostream>
using namespace std;

// String 클래스 제공
class String {
public:
    String();
    String(const char* str);
    String(const String& str);
    String& operator=(const String& str);
    ~String();
    const char* data() const;
    char& at(size_t);
    size_t size() const;
    void print(const char* str="") const;
private:
    void swap(String& str);
    int len;
    char* s;
};

String::String() { // 기본(empty) 생성자
    s = new char[1];
    s[0] = '\0';
    len = 0;
}

String::String(const char* str) { // 생성자
    len = 0;
    while(str[len] != '\0') len++;

    if(str) {
        s = new char[len + 1];
        std::copy(str, str+len+1, s);
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

String::~String(){
    delete[] s;
}

String& String::operator=(const String& str){ // 복사 대입 생성자
    if (this != &str) { // 자기대입 check
        len = str.len;
        delete[] s;
        s = new char[len + 1];
        std::copy(str.s, str.s+len+1, s);
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
    // 사용하지 않는 함수
}
