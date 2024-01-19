#include <memory>
#include "University.h"
#include "Department.h"
#include "Faculty.h"

// main.cpp 제공
int main() {
    auto faculty = std::make_shared<Faculty>("Computer Science", 10);

    Department cse("Computer Science and Engineering", faculty.get());
    Department ibe("Information and Biomedical Engineering");
    ibe.setFaculty(faculty.get());
    
    Department depts[3] = {Department("Math"), ibe, cse };
    University univ("Pusan National University", 3);
    univ.setDepartments(depts);
    
    univ.printInfo();

    return 0;
}
// // faculty.h
// #include <iostream>
// #include <string>
// using namespace std;

// class Faculty{
//     string name;
//     int num;
// public:
//     Faculty(string name="", int num=0): name(name), num(num) { }

//     const Faculty* get() const{return this;}
//     string getName(){return this->name;}
//     int getNum(){return this->num;}
// };
// // department.h
// #include "Faculty.h"

// class Department{
//     string name;
//     Faculty* faculty;
// public:
//     Department(string name, Faculty* faculty=nullptr): name(name), faculty(faculty) { }

//     Faculty* getFaculty(){return this->faculty;}
//     void setFaculty(Faculty* faculty){this->faculty = faculty;}
//     string getName(){return this->name;}
// };
// // university.h
// #include "Department.h"

// class University{
//     string name;
//     int num;
//     Department* departments;
// public:
//     University(string name, int num): name(name), num(num) { }

//     void setDepartments(Department* dept){this->departments = dept;}
//     void printInfo(){
//         cout << "University Name: " << this->name << endl;
//         cout << "Number of Departments: " << this->num << endl << endl;

//         for(int i=0; i<num; i++){
//             cout << "Department Name: " << this->departments[i].getName() << endl;
//             if(auto tmp = this->departments[i].getFaculty()){
//                 cout << "Faculty Name: " << tmp->getName() << endl;
//                 cout << "Number of Faculty Members: " << tmp->getNum() << endl << endl;
//             }
//             else{
//                 cout << "Faculty Name: N/A" << endl;
//                 cout << "Number of Faculty Members: N/A" << endl << endl;
//             }
//         }
//     }
// };
