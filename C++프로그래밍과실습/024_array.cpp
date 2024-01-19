#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main() {
    array<int, 10> arr;
    for (auto &iter: arr)
        cin >> iter;

    auto result = std::minmax_element(begin(arr), end(arr));
    auto min = result.first;
    auto max = result.second;

    cout << *max << " " << *min;
}
