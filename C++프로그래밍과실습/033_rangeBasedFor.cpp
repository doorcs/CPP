#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n{};
    cin >> n;

    vector<int> v(n);
        // for (int i{}; i<n; i++){
        //     int tmp{};
        //     cin >> tmp;
        //     v.push_back(tmp);
        // }

    for (auto& value: v){ // for (int &value: v)
        cin >> value;
    }

    int sum{};
    for (int i: v)
        sum += i;
    cout << sum;
}