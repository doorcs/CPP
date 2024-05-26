// ref: https://en.cppreference.com/w/cpp/language/structured_binding

#include <iostream>
#include <utility> // std::pair

int main() {
    int val;
    std::cin >> val;
    
    int copiedVal_1 = val; // val변수의 값을 새로운 변수에 복사
    auto copiedVal_2 = val; // 이런 상황에서 auto 키워드를 활용할 수도 있음! ( 컴파일러가 타입을 추론 )

/////////////////////////////////////////////////////////////////////////////////////////////

    std::pair<int, int> pii{9999, 2'147'483'647}; // std::pair의 첫번째 요소는 `.first`로, 두번째 요소는 `.second`로 접근할 수 있음
    
    int copiedFirst_1 = pii.first; // pair의 첫번째 요소 값을 새로운 변수에 복사
    auto copiedSecond_1 = pii.second; // 마찬가지로 auto 키워드를 활용할 수 있음

    /***** structured binding에 이미 사용된 변수명을 다시 사용하면 에러가 발생함!! 변수를 만들면서 바인딩까지 한번에 처리하는 것! *****/

    // 변수 두 개를 선언하는 동시에, pair의 first와 second값을 `복사`로 바인딩 (C++17)
    auto [copiedFirst_2, copiedSecond_2] = pii; // auto [`변수명1`, `변수명2`] = `std::pair객체`;

    // 변수 두 개를 선언하는 동시에, pair의 first와 second를 `레퍼런스`로 바인딩 (C++17)
    auto& [referencedFirst, referencedSecond] = pii; // auto& [`변수명1`, `변수명2`] = `std::pair객체`;

    // `const auto& [a, b]`도 가능!

    /* C++17 이전: `std::tie()`를 활용 ( auto& [,] 처럼 레퍼런스로 바인딩됨 )
     * int a, b;
     * std::tie(a, b) = pii; // std::tie를 활용할 땐 structural binding과는 다르게 변수를 미리 선언해둬야함!!
     */

    pii.first = -9999; // 원본 pair(pii)를 수정
    pii.second = -2'147'483'648;
    
    // 복사로 바인딩한 변수들의 값은 변하지 않고, 레퍼런스로 바인딩한 변수의 값은 변함!!
    std::cout << val << ' ' << copiedVal_1 << ' ' << copiedVal_2 << '\n'
              << pii.first << ' ' << pii.second << '\n' // 원본 pair 출력
              << copiedFirst_1 << ' ' << copiedSecond_1 << '\n' // 변경 전 pair의 값들이 출력됨
              << copiedFirst_2 << ' ' << copiedSecond_2 << '\n' // 마찬가지
              << referencedFirst << ' ' << referencedSecond << std::endl; // 원본 pair와 같은 값들이 출력됨
}
