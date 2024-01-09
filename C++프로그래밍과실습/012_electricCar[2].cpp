#include <iostream>
#include <iomanip>
#include <string>
#include <map>
using namespace std;

int NEXT_WAYPOINT = 100;

int main() {
    map<int, string> mp{{100, "Gyeongsan"}, {200, "Gimcheon"}, {300, "Cheongju"}, {400, "Anseong"}};

    double capacity, efficiency, battery_level, distance;
    cin >> capacity >> efficiency >> battery_level >> distance;

    const double km_per_kW = capacity / 100 * efficiency;
    double now = 0;
    
    cout << fixed << setprecision(2) << "Current battery level: " << battery_level << "%, after traveling " << now << " km." << endl;
    while (now < distance) {
        battery_level--;
        now += km_per_kW;
        if(now >= distance) break;

        if(static_cast<int>(now + km_per_kW) / 100 != static_cast<int>(now) / 100){ // now의 백의 자리가 바뀔 때마다 확인
            if ((distance - now) < NEXT_WAYPOINT && battery_level - (distance-now)/km_per_kW <= 20 || distance - now > NEXT_WAYPOINT && battery_level - 100/km_per_kW <= 20){ // 목적지가 다음 waypoint보다 가까울 때 || 목적지가 다음 waypoint보다 멀 때
            cout << "Current battery level: " << battery_level << "%, after traveling " << now << " km." << endl;
            cout << "Battery at " << battery_level << "%, stopping at " << mp[static_cast<int>((now + km_per_kW) / 100) * 100] << " for charging." << endl;
            battery_level = 80;
            now = (static_cast<int>(now + km_per_kW) / 100) * 100;
            }
        }

        if (static_cast<int>(battery_level) % 10 == 0) 
            cout << "Current battery level: " << battery_level << "%, after traveling " << now << " km." << endl;
    }
    cout << "Arrived in Seoul with " << battery_level << "% battery remaining.";
}
