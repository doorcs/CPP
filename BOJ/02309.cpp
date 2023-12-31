#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    vector<int> v(9);
    for(int &iter: v) cin >> iter;
    int sum=0;
    for(int iter: v) sum += iter;

    sort(v.begin(), v.end());

    for(int i=0; i<v.size()-1; i++){
        for(int j=i+1; j<v.size(); j++){
            if (v[i]+v[j] == sum-100) {
                v.erase(v.begin()+j); // 뒤쪽에 있는걸 먼저 지우면 인덱스 바뀌는걸 신경 안 써줘도 된다
                v.erase(v.begin()+i);
                for(auto it: v) cout << it << endl; // goto 쓰지 말고, 메인함수를 끝내기
                return 0;
            }
        }
    }
}
