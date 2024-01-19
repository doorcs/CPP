#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n);
    for(int i=0; i<n; i++){
        int len;
        cin >> len;
        for(int j=0; j<len; j++){
            int tmp;
            cin >> tmp;
            v[i].push_back(tmp);
        }
    }
    for(int i=0; i<m; i++){
        int vi, vidx;
        cin >> vi >> vidx;
        cout << v[vi][vidx] << endl;
    }
}
