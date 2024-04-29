#include <ranges> // C++20
#include <iostream>
#include <vector>

using namespace std; // `std::views::` 대신 `views::`를 쓰기 위해

int main() {
    vector<int> vi{1, -3, 5, -7, 9}; // std::vector 컨테이너는 `range concept`을 만족한다

    auto vw1 = vi | views::filter([](auto a){ // `std::ranges::filter_view` 타입의 view
        return a > 0;
    }); // pipe 사용하기 (`operator |` 오버로딩)

    auto vw2 = views::filter(vi, [](auto a){
        return a < 0;
    }); // range를 직접 파라미터로 넘겨주기


    // 여러 view들을 파이프라이닝:

    auto vw3 = views::iota(0, 10) // 0에서 10까지를 가지는 iota_view 생성 (0 포함 10 제외 == {0, 1, 2, 3, 4, 5, 6, 7, 8, 9})
             | views::filter([](auto a){ return a&1; }) // 홀수만 남도록 filter // {1, 3, 5, 7, 9}
             | views::transform([](auto a){ return a*a; }); // 제곱 // {1, 9, 25, 49, 81}
    // 마지막에 적용된게 std::views::transform()이기 때문에, `std::ranges::transform_view`타입의 view!

    auto vw4 = views::iota(0, 10) // 0에서 10까지를 가지는 iota_view 생성 (0 포함 10 제외 == {0, 1, 2, 3, 4, 5, 6, 7, 8, 9})
             | views::transform([](auto a){ return a*a; }) // 제곱 // {0, 1, 4, 9, 16, 25, 36, 49, 64, 81}
             | views::filter([](auto a){ return a&1; }); // 홀수만 남도록 filter // {1, 3, 5, 7, 9}
    // 마지막에 적용된게 std::views::filter()이기 때문에, `std::ranges::filter_view`타입의 view

    for (const auto& it : vw1) cout << it << ' '; // { 1, 5, 9 }
    cout << '\n';
    for (const auto& it : vw2) cout << it << ' '; // { -3, -7 }
    cout << '\n';
    for (const auto& it : vw3) cout << it << ' '; // { 1, 9, 25, 49, 81 }
    cout << '\n';
    for (const auto& it : vw4) cout << it << ' '; // { 1, 9, 25, 49, 81 } // vw3과 같은 내용의 view
}

/*
 * C++20의 `views`. `range concept`을 만족하는 경우에 사용할 수 있으며, 여러 장점들을 가지고 있다
 * C++17에 들어온 std::string_view와 비슷한 개념. 원본 데이터를 훼손하지 않는다!
 * view(views)는 `원본에 대한 참조`만을 가지며, 데이터를 실제로 가지고 있지 않는다
 * 원본 데이터를 복사하지 않기 때문에 view를 사용하면 메모리 사용량이 줄어들고, 데이터를 처리하는 데 들어가는 시간도 짧아진다
 * `range`에 std::views::filter()나 std::views::transform() 등을 적용하면 연산이 즉시 실행되지 않는다!!! 반복문이나 다른 알고리즘에서 사용하는 요소에 대해서만 *Lazy* 하게 처리된다
 * == view는 실제로 연산이 필요해지는 시점까지 연산(데이터 처리)을 미룬다. 불필요한 연산은 수행하지 않음으로써 성능을 향상시킬 수 있다
 * 파이프(|)를 사용해 여러 view들을 연결할 수 있다! 한 view의 출력을 다른 view의 입력으로 리디렉션(연결?)시켜 데이터의 흐름을 간결하게 표현할 수 있다
 * 여러 view들이 파이프라이닝될 때, *중간 결과들을 저장하지 않고 최종 결과만을 계산* 함으로써 메모리 사용량도 줄어들고 계산 시간도 짧아진다
 * 
 * +++ 단, view가 사용되는 동안에는 view에서 참조하는 원본 `range`가 유효해야 한다!!! 즉, 원본 range의 수명은 반드시 view보다 길어야 한다!
 */
