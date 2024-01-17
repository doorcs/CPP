// 제공된 파일
#include <iostream>
#include <stddef.h>
using namespace std;

class String {
public:
    String();
    String(const char* str);
    String(const String& str);
    String& operator=(const String& str);
    ~String() noexcept;
    const char* data() const;
    char& at(size_t);
    size_t size() const;
    void print(const char* str="") const;
private:
    void swap(String& str); // 안 쓰고, 구현 안 해도 main 잘 돌아감
    int len;
    char* s;
};
