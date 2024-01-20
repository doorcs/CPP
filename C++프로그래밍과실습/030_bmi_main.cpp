// main.cpp 제공 
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include "030_bmi.h"
using namespace std;

int main() {
    int rep;
    cin >> rep;
    vector<unique_ptr<PatientInfo>> patients;

    for(int i=0; i<rep; i++){
        PatientInfo newPatient;
        cin >> newPatient.name >> newPatient.age >> newPatient.weight >> newPatient.height;

        addinfo(newPatient, patients);
    }

    printAll(patients);
    cout << endl;

    cout << "Enter the name: ";
    string query;
    cin >> query;
    searchInfo(patients, query);
    cout << endl;

    cout << "Enter the BMI threshold: ";
    double threshold;
    cin >> threshold;
    printAbove(patients, threshold);
    cout << endl;

    cout << "Enter the BMI threshold: ";
    cin >> threshold;
    remove(patients, threshold);

    printAll(patients);
}
