#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    int num;
    while(cin>>num){ // EOF를 만날때까지 반복
        v.push_back(num);
    }
    auto val = minmax_element(v.begin(), v.end());
    auto min = val.first;
    auto max = val.second;

    cout << v.size() << ' ' << *min << ' ' << *max << endl;
}
