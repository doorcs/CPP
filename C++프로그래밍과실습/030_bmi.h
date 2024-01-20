#include <iostream>
#include <memory>
#include <iomanip>
#include <algorithm>
using namespace std;

struct PatientInfo{
    string name;
    int age;
    double weight;
    double height;
    double bmi;
};

void addinfo(const PatientInfo&, vector<unique_ptr<PatientInfo>>& ); // 추가

void printInfo(unique_ptr<PatientInfo>& ); // 출력 한번

void printAll(vector<unique_ptr<PatientInfo>>& ); // 전체출력

void searchInfo(vector<unique_ptr<PatientInfo>>&, string); // 이름으로검색

void printAbove(vector<unique_ptr<PatientInfo>>&, double); // BMI가 double값 이상이면 출력

void remove(vector<unique_ptr<PatientInfo>>&, double); // BMI가 double값 이하면 삭제
