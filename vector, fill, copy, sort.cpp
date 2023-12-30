#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // int a[10];
    // fill(&a[0], &a[10], 0);

    // for(int &iter: a) cin >> iter;
    // for(int iter: a) cout << iter << endl;

    vector<int> a{1, 3, 2};
    vector<int> b(3);
    copy(a.begin(), a.end(), b.begin());
    
    for(int iter: b) cout << iter << endl;
    sort(a.begin(), a.end());

    for(int iter: a) cout << iter << ' ';
    cout << endl;

    sort(b.begin(), b.end(), greater());
    for(int iter: b) cout << iter << ' ';
    cout << endl;

    // cout << &*(b.end()-1) << endl << &*(b.end()) << endl;
}
