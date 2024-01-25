#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int size;
    cin >> size;

    vector<int> v(size);
    for(auto& it: v) cin >> it;

// 명령1: 벡터의 위치(인덱스)를 나타내는 정수가 제공되며, 주어진 벡터에서 해당 위치의 원소를 삭제 
    int a;
    cin >> a;
    v.erase(v.begin() + a);

// 명령2: 벡터의 값을 나타내는 정수가 제공되며, 주어진 벡터에서 해당 값을 가지는 원소를 모두 삭제
    int b;
    cin >> b;
    v.erase(remove(v.begin(), v.end(), b), v.end());

// remove(iter, iter, value)는 value를 삭제한 뒤, 값이 보장되지 않기 시작하는 지점의 "이터레이터를 반환"
//
// 1, 2, 3, 4, 5 가 있는 벡터 v에서
// `v.erase(v.begin(), v.end(), 3)` 함수를 실행하면 
// 1, 2, 4, 5 가 되는게 아니라
// 1, 2, 4, 5, 5 가 되고,
// 함수는 두번째 5를 가리키는 이터레이터를 반환한다.
//
// 즉 remove는 `값 삭제 + 삭제된 값 뒤에 있던 값들 당겨오기` 까지만 수행하고 당겨오기가 끝난 지점 뒤의 값들은 건드리지 않는다. 
// 그래서 직관적이지 않지만 반드시 vector.erase() 함수와 같이 사용해줘야한다!
  
// v.erase(remove(v.begin(), v.end(), value), v.end());

    cout << v.size() << endl;
    for(auto it: v) cout << it << ' ';
    cout << endl;
}
