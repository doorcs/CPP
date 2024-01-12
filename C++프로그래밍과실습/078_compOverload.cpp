#include "078_compOverload.h"

bool compareByGrade(const Student& a, const Student& b){
    return a.grade > b.grade;
}

bool Student::operator<(const Student& other) const{
    return name < other.name;
}

ostream& operator<<(ostream& os, const Student& s) {
    return os << "Id: " << s.id << " Name: " << s.name << " Grade: " << s.grade;
}
