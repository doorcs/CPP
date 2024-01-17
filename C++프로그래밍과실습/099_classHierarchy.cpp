#include <iostream>
#include <string>
using namespace std;

// Employee 클래스만 제공
class Employee {
public:
    Employee(string name, int salary) : name_(name), salary_(salary) {}
    virtual void print_report() const { 
        cout << "Name: " << name_ << endl;
        cout << "Salary: " << salary_ << endl;
        cout << "Years of service: " << years_of_service_ << endl;
        cout << "Performance score: " << performance_score_ << endl;
    }
    string get_name() const {
        return name_;
    }
protected:
    string name_;
    int salary_;
    int years_of_service_ = 0;
    int performance_score_ = 0;
};

class Manager: public Employee{
    string department_;
public:
    Manager(string name, int salary, string department): Employee(name, salary), department_(department) { }
    void set_goals(){
        cout << "Set goals for " << department_ << endl;
    }
    void print_report() const override{
        Employee::print_report();
        cout << "Department: " << department_ << endl;
    }
};
class Programmer: public Employee{
    string language_;
public:
    Programmer(string name, int salary, string language): Employee(name, salary), language_(language) { performance_score_ = 10; }
    void write_code(){
        cout << "Writting code in " << language_ << endl;
    }
    void print_report() const override{
        Employee::print_report();
        cout << "Language: " << language_ << endl;
    }
};
class Salesperson: public Employee{
    int sales_;
public:
    Salesperson(string name, int salary, int sales): Employee(name, salary), sales_(sales) { performance_score_ = 20; }
    void sell(){
        cout << "Selling products, generated " << sales_ << " in revenue" << endl;
    }
    void print_report() const override{
        Employee::print_report();
        cout << "Sales: " << sales_ << endl;
    }
};
// 아래는 제공된 코드
int main() {
    Manager m = Manager("Alice", 50000, "Marketing");
    Programmer p = Programmer("Bob", 60000, "C++");
    Salesperson s = Salesperson("Charlie", 40000, 100000);

    m.set_goals();
    p.write_code();
    s.sell();

    Employee* e1 = &m;
    Employee* e2 = &p;
    Employee* e3 = &s;

    e1->print_report();
    e2->print_report();
    e3->print_report();
}
