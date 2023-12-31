#include <iostream>
#include <algorithm>
#include <array>
// `type arrname[size]` 방식의 배열 말고, `array<type, size> arrname`방식의 배열을 사용하기 위해 필요
using namespace std;

int main() {
    array<int, 10> arr;
    for (auto &iter: arr)
        cin >> iter;

    auto result = minmax_element(begin(arr), end(arr));
    auto min = result.first;
    auto max = result.second;

    cout << *max << " " << *min << endl;
}