#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    // 처음 떠올렸던 방법
    vector<int> v1;

    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        v1.push_back(tmp);
    }

    // 더 효율적인 방법
    vector<int> v2(n);

    for(int i=0; i<n; i++) cin >> v2[i];

}
