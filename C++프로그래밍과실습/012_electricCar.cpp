#include <iostream>
#include <iomanip>
// using namespace std; // std::distance 변수명 충돌

double capacity, efficiency, battery_level, distance;
int f1, f2, f3, f4; // 플래그

int main() {
    std::cin >> capacity >> efficiency >> battery_level >> distance;

    const double km_per_kW = capacity / 100 * efficiency;
    double now = 0;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Current battery level: " << battery_level << "%, " << "after traveling " << now << " km." << std::endl;
    while (now < distance) {
        battery_level--;
        now += km_per_kW;

        if(now >= distance) break;
        if (static_cast<int>(battery_level) % 10 == 0)
            std::cout << "Current battery level: " << battery_level << "%, " << "after traveling " << now << " km." << std::endl;

        if (now + km_per_kW > 100 && f1 == 0) {
            f1 = 1;
            if (((distance-now) < 100 && battery_level - (distance-now)/km_per_kW <= 20) || ((distance-now) > 100 && battery_level - 100/km_per_kW <= 20)) {
                std::cout << "Current battery level: " << battery_level << "%, " << "after traveling " << now << " km." << std::endl;
                std::cout << "Battery at " << battery_level << "%, " << "stopping at Gyeongsan for charging." << std::endl;
                battery_level = 80;
                now = 100;
                std::cout << "Current battery level: " << battery_level << "%, " << "after traveling " << now << " km." << std::endl;
            }
            }
        if (now + km_per_kW > 200 && f2 == 0) {
            f2 = 1;
            if (((distance-now) < 100 && battery_level - (distance-now)/km_per_kW <= 20) || ((distance-now) > 100 && battery_level - 100/km_per_kW <= 20)) {
                std::cout << "Current battery level: " << battery_level << "%, " << "after traveling " << now << " km." << std::endl;
                std::cout << "Battery at " << battery_level << "%, " << "stopping at Gimcheon for charging." << std::endl;
                battery_level = 80;
                now = 200;
                std::cout << "Current battery level: " << battery_level << "%, " << "after traveling " << now << " km." << std::endl;
            }
            }
        if (now + km_per_kW > 300 && f3 == 0) {
            f3 = 1;
            // if(battery_level <= 40){
            if (((distance-now) < 100 && battery_level - (distance-now)/km_per_kW <= 20) || ((distance-now) > 100 && battery_level - 100/km_per_kW <= 20)) {
                std::cout << "Current battery level: " << battery_level << "%, " << "after traveling " << now << " km." << std::endl;
                std::cout << "Battery at " << battery_level << "%, " << "stopping at Cheongju for charging." << std::endl;
                battery_level = 80;
                now = 300;
                std::cout << "Current battery level: " << battery_level << "%, " << "after traveling " << now << " km." << std::endl;
            }
            }
        if (now + km_per_kW > 400 && f4 == 0) {
            f4 = 1;
            if (((distance-now) < 100 && battery_level - (distance-now)/km_per_kW <= 20) || ((distance-now) > 100 && battery_level - 100/km_per_kW <= 20)) {
                std::cout << "Current battery level: " << battery_level << "%, " << "after traveling " << now << " km." << std::endl;
                std::cout << "Battery at " << battery_level << "%, " << "stopping at Anseong for charging." << std::endl;
                battery_level = 80;
                now = 400;
                std::cout << "Current battery level: " << battery_level << "%, " << "after traveling " << now << " km." << std::endl;
            }
            }
    }
    std::cout << "Arrived in Seoul with " << battery_level << "% battery remaining." << std::endl;
}
