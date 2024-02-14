#include <iostream>
#include <initializer_list>
#include <algorithm>
using namespace std;

int main() {
    // initializer_list와 range-based-for문을 함께 사용할 수 있다 (C++11)
    for(int i: {3, 8, 3, 6}) cout << i << ' '; // 3 8 3 6
    cout << '\n';
  
    // 변수와 함께 사용할 수도 있다
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for(const auto& i: {d, b, a, c}) cout << i << ' '; // 순서도 마음대로 설정가능
    cout << '\n';

// =================================================================================

    // min이나 max함수의 인자로 initializer_list를 사용할 수 있다 (C++11)
    int res1 = max({6, 2, 7, 3});
    cout << res1 << '\n'; // 7

    // 마찬가지로 변수와 함께 사용 가능
    int res2 = std::max({a, b, c, d}); // 앞의 예시에서 선언 && cin으로 값 대입해둔 변수 `a`, `b`, `c`, `d` 사용
    cout << res2 << '\n';
}

//// `initializer_list`를 활용하지 않아 비효율적인 코드 예시:

// int li[] = {3, 8, 3, 6};
// for(int it: li) cout << it << ' ';

// max(7, max(3, 6));
// max(6, max(2, max(7, 3)));
