#include <iostream>
#include <string>
using namespace std;

class Student{
public:
    Student(int id=0, string name="", int grade=0): id(id), name(name), grade(grade) { }
//  Student(int id, string name, int grade): id(id), name(name), grade(grade) { } 
//  이처럼 생성자를 기본값 없이 선언하면 Student(); 꼴의 기본 생성자는 사용할 수 없게 되기 때문에 main의 map[1] = {1, "Bob", 90}; 에서 오류가 발생한다.

    bool operator<(const Student& other) const;
    friend ostream& operator<<(ostream& os, const Student& s);
    friend bool compareByGrade(const Student& a, const Student& b);
private:
    int id;
    string name;
    int grade;
};

bool compareByGrade(const Student& a, const Student& b);
