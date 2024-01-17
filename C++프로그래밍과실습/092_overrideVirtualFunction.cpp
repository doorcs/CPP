#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Vehicle{
public:
    virtual void accelerate() = 0;
};

class GV70: public Vehicle{
    string name;
    int speed;
public:
    GV70(): name("gv70"), speed(30){ } // 아무 인자도 받지 않는 기본 생성자도 초기화 리스트를 사용할 수 있다!!!!!!

    void accelerate(){
        cout << "The speed of the " << name << " has increased by " << speed << " km/h." << endl;
    }
};

class Grandeur: public Vehicle{
    string name;
    int speed;
public:
    Grandeur(): name("grandeur"), speed(20){ } // 아무 인자도 받지 않는 기본 생성자도 초기화 리스트를 사용할 수 있다!!!!!!

    void accelerate(){
        cout << "The speed of the " << name << " has increased by " << speed << " km/h." << endl;
    }
};

class Carnibal: public Vehicle{
    string name;
    int speed;
public:
    Carnibal(): name("carnibal"), speed(10){ } // 아무 인자도 받지 않는 기본 생성자도 초기화 리스트를 사용할 수 있다!!!!!!

    void accelerate(){
        cout << "The speed of the " << name << " has increased by " << speed << " km/h." << endl;
    }
};
// 아래는 제공된 코드입니다.
unique_ptr<Vehicle> make_vehicle() {
    std::string choice;
    cin >> choice;

    if (choice == "gv70") return make_unique<GV70>();
    else if (choice == "grandeur") return make_unique<Grandeur>();
    else if (choice == "carnibal") return make_unique<Carnibal>();
    else return make_unique<GV70>();
}

int main() {
    vector<unique_ptr<Vehicle>> test_vehicles;
    test_vehicles.push_back(make_vehicle()); //gv70
    test_vehicles.push_back(make_vehicle()); //grandeur
    test_vehicles.push_back(make_vehicle()); //carnibal

    for (auto& v : test_vehicles)
            (*v).accelerate();
}
