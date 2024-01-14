#include <iostream>
#include <string>
using namespace std;

class Person{
    string name;
public:
    Person(string name=""): name(name) {
        cout << "Person is constructed!" << endl;
    }
    ~Person(){ cout << "Person is destructed!" << endl; }
    void print(){
        cout << "Person Name: " << this->name << endl;
    }
    string getName(){
        return name;
    }
};

class Student: public Person{
    string univ;
public:
    Student(string name="", string univ=""): Person(name), univ(univ) {
        cout << "Student is constructed!" << endl;
    }
    ~Student(){ cout << "Student is destructed!" << endl; }
    void print(){
        cout << "Person Name: " << Person::getName() << endl << "School Name: " << univ << endl;
    }
};

int main() {
    Person p1{"Park"};
    p1.print();

    Student s1 {"Kim", "PNU"};
    s1.print();

    return 0;
}
