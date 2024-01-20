#include "030_bmi.h"

void addinfo(const PatientInfo& newPatient, vector<unique_ptr<PatientInfo>>& infolist){
    unique_ptr<PatientInfo> newinfo = make_unique<PatientInfo>();

    newinfo->name = newPatient.name;
    newinfo->age = newPatient.age;
    newinfo->weight = newPatient.weight;
    newinfo->height = newPatient.height;
    newinfo->bmi = newPatient.weight / (newPatient.height * newPatient.height);

    infolist.push_back(std::move(newinfo));
}

void printInfo(unique_ptr<PatientInfo>& info){
    cout << fixed << setprecision(2);
    cout << info->name << ' ' << info->age << ' ' << info->weight << ' ' << info->height << ' ' << info->bmi << endl;
}

void printAll(vector<unique_ptr<PatientInfo>>& infolist){
    // 정렬: [](PatientInfo a, PatientInfo b){return a->bmi < b->bmi;} // std::sort 3번째 인자로 람다함수 이용
    sort(infolist.begin(), infolist.end(), [](auto& a, auto& b) {
        return a->bmi > b->bmi;
    });

    cout << "Information for all patients:" << endl;
    for(auto& it: infolist){
        printInfo(it);
    }
}

void searchInfo(vector<unique_ptr<PatientInfo>>& infolist, string name){
    for(auto& it: infolist){
        if(name == it->name) {
            cout << "Patient found: " << endl;
            printInfo(it);
            break;
        }
    }
}

void printAbove(vector<unique_ptr<PatientInfo>>& infolist, double threshold){
    cout << "Patients with BMI more than " << threshold << ':' << endl;

    for(auto& it: infolist){
        if(it->bmi > threshold)
            printInfo(it);
    }
}

void remove(vector<unique_ptr<PatientInfo>>& infolist, double threshold){
    auto rm = remove_if(infolist.begin(), infolist.end(), [threshold](auto& a){return a->bmi <= threshold;});
    infolist.erase(rm, infolist.end());
}
