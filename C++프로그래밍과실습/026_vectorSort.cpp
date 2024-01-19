#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int size;
    cin >> size;

    vector<int> v(size);
    for(auto &it: v) cin >> it;

    sort(v.begin(), v.end());
    for(auto it: v) cout << it << ' ';
    cout << endl;
}
