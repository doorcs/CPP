#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "student.h"
using namespace std;

int main() {
    int rep;
    cin >> rep;

    vector<pair<string, int>> vec;
    for(int i=0; i<rep; i++) {
        string name;
        int age;
        cin >> name >> age;
        vec.push_back({name, age});
    }

    for(const auto& it: vec){
        unique_ptr pt = createStudent(it.first, it.second);
        printStudentInfo(*pt);
    }
}