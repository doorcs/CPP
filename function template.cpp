#include <iostream>
#include <vector>
using namespace std;

template <typename T> // `typename` 또는 `class` 둘 다 사용가능. 관습적으로 인자명은 `T`, `U`를 사용
const T* find(const vector<T>& data, const T& v){ // 이건 실제 함수가 아니다. 함수를 만들 수 있는 템플릿
    for(int i{}; i<data.size(); i++){
        if(data[i] == v) return &data[i];
    }
    return nullptr;
}

int main(){
    vector<int> v;

    for(int i=1; i<10; i++) v.push_back(i);
    v.erase(remove(v.begin(), v.end(), 3), v.end());

    auto search3 = find(v, 3); // nullptr
    auto search4 = find(v, 4); // 벡터에 들어있는 `4`의 주소

    if(search3 != nullptr) cout << *search3 << endl; // 출력 X
    // nullptr를 참조하면 segfault!
    if(search4 != nullptr) cout << *search4 << endl; // 4

    // cout << *search3 << ' ' << *search4 << endl; // `*search3`때문에 segmentation fault 발생
}
