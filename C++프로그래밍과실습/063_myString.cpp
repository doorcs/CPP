#include "String.h"
#include <cstring>
using namespace std;

int String::count_ = 0; // static 변수 초기화

String::String() { // 기본 생성자
    len_ = 0; // 문자열의 길이는 0이지만
    data_ = new char[len_ + 1]; // 공간은 1이고 (문자열 맨 마지막은 null문자 '\0\'가 들어가야 하기 때문 << data_ = new char[len_ + 1]; 이랑 같다
    data_[0] = '\0'; // 할당받은 1의 공간에 '\0' null문자 넣기
    cout << "Default Constructor" << endl;
    count_++; // static 변수인 count_ 1 증가시키고, 출력 처리
    cout << "# of String object: " << count_ << endl;
}

String::~String() noexcept { // 소멸자: 소멸자는 생성자 종류에 상관없이 공통으로 사용 가능하도록
    delete[] data_; // delete[] data_;
    cout << "Destructor" << endl;
    count_--;
    cout << "# of String object: " << count_ << endl;
}

String::String(const char* str) { // C 스타일 문자열을 입력으로 받았을 때 처리하는 생성자
    if (str) { // 빈 문자열이 아니라면 if문 안쪽으로 들어감
        len_ = strlen(str); // 문자열의 길이는 입력받은 C-style string의 길이. 이때 strlen(str);을 이용
        data_ = new char[len_ + 1]; // data_ = new char[len_ + 1];
        strcpy(data_, str); // strcpy(data_, str);
    } else { // 빈 문자열을 입력받았다면 default constructor와 똑같이 처리!
        len_ = 0;
        data_ = new char[1];
        data_[0] = '\0';
    }
    cout << "Constructor" << endl;
    count_++;
    cout << "# of String object: " << count_ << endl;
}

String::String(const String& str) noexcept { // 다른 String 객체를 복사해서 생성할 때
    len_ = str.len_; // len_ = str.len_;
    data_ = new char[len_ + 1]; // data_ = new char[len_ + 1];
    strcpy(data_, str.data_); // strcpy(data_, str.data_);
    cout << "Copy Constructor" << endl;
    count_++;
    cout << "# of String object: " << count_ << endl;
}

const char* String::data() const { // 그냥 return data_;
    return data_;
}

bool String::empty() const { // 그냥 return len_ == 0; ( 길이가 0이면 true, 0이 아니면 false 반환 )
    return len_ == 0;
}

size_t String::size() const { // 그냥 return len_;
    return len_;
}

String& String::append(const String& str) {
    char* new_data = new char[len_ + str.len_ + 1];
    strcpy(new_data, data_);
    strcat(new_data, str.data_);

    delete[] data_;
    data_ = new_data;
    len_ += str.len_;

    return *this;
}
