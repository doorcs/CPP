#include <iostream>
#include <string>
#include <map>
using namespace std;

class Person {
public:
    Person(string name="", string number=""); // map을 클래스와 함께 사용할땐 꼭 기본 생성자를 넣어주기!!! map의 [key, value]에서 value가 클래스일 때 기본 생성자 없으면 실행 불가
    void modifyNumber(string number);
    void print() const;

private:
    string name;
    string phoneNumber;
};
