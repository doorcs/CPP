#include <iostream>
#include <initializer_list>
#include <algorithm>
using namespace std;

int main() {
    // initializer_list와 range-based-for문을 함께 사용할 수 있다 (C++11)
    for(int i: {3, 8, 3, 6}) cout << i << ' '; // 3 8 3 6
  
    // 변수와 함께 사용할 수도 있다
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for(const auto& i: {d, b, a, c}) cout << i << ' '; // 순서도 마음대로 설정가능

// ==================================================================================

    // min이나 max함수의 인자로 initializer_list를 사용할 수 있다 (C++11)
    int res = max({6, 2, 7, 3});
    cout << res << '\n'; // 7
}

// int li[] = {3, 8, 3, 6};
// for(int it: li) cout << it << ' ';

// max(7, max(3, 6));
// max(6, max(2, max(7, 3)));
