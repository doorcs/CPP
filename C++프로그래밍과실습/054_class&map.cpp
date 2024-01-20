#include "054_class&map.h"

Person::Person(string name, string number) : name(name), phoneNumber(number) {}

void Person::modifyNumber(string number) {
    phoneNumber = number;
}
void Person::print() const {
    cout << name << " " << phoneNumber << endl;
}
