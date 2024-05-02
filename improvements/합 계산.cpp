#include <numeric>
#include <iostream>
#include <vector>
// #include <functional> // for function objects (plus{}, minus{}, multiplies{}, divides{}, ...)
using namespace std;

int main() {
    vector<int> vi{1, 3, 5, 7, 9}; // 합: 25

    // for loop
    int sum1 = 0;
    for (size_t i = 0; i < vi.size(); i++) sum1 += vi[i];

    // (C++11) range-based for loop
    int sum2 = 0;
    for (int it : vi) sum2 += it;

    // std::accumulate(begin, end, init)
    int sum3 = accumulate(vi.begin(), vi.end(), 0); // [begin, end) 범위의 값들을 init값에 차례대로(왼쪽에서부터 순차적으로) 더한다

    // (C++17) std::reduce(begin, end), std::reduce(begin, end, init)
    int sum4 = reduce(vi.begin(), vi.end(), 0); // std::accumulate와 비슷하지만, 연산 순서가 임의로 변경될 수 있다
    int sum5 = reduce(vi.begin(), vi.end()); // `initial value`가 없는 오버로딩 형태도 존재한다! (파라미터가 두 개인 오버로딩 형태가 존재)


    cout << sum1 << ' ' << sum2 << ' ' << sum3 << ' ' << sum4 << ' ' << sum5;
}

// `std::reduce()`와 `std::accumulate()`의 차이점, `std::reduce()`사용시 주의사항:

/*
 * https://en.cppreference.com/w/cpp/algorithm/reduce
 * Notes - std::reduce behaves like std::accumulate except the `elements of the range may be grouped and rearranged` in arbitrary order.
 * 
 * std::accumulate()는 기본적으로 덧셈을 수행하지만, 네번째 파라미터로 function(operation)을 받을 수 있다.
 * auto result = std::accumulate(begin(), end(), init, func);
 * 이때의 동작은 아래와 같다:
 *
 *    result = init;
 *    for (auto it = begin(); it != end(); it++) { // iterator의 범위는 [begin, end)
 *        result = func(result, *it);
 *    }
 * 
 * !!! std::reduce()의 경우 `연산 순서가 임의로 변경될 수 있다`는 점은 기본값인 덧셈에서는 아무 의미 없지만,
 * !!! 교환법칙과 결합법칙이 성립하지 않는 다른 연산에서는 문제가 될 수 있다! (뺄셈, 나눗셈처럼!)
 *
 *    // 곱셈은 associative && commutative -> accumulate()와 reduce()의 결과가 항상 같다
 *    int mul1 = accumulate(vi.begin(), vi.end(), 0, [](int a, int b){ return a * b; });
 *    int mul2 = reduce(vi.begin(), vi.end(), 0, multiplies{}); // `std::multiplies`는 위 람다식과 같은 역할을 함
 *
 *    // 뺄셈이나 나눗셈에 std::reduce()를 사용하면 문제가 생길 수 있다!!!
 *    int sub1 = accumulate(vi.begin(), vi.end(), 0, minus<void>()); // 템플릿 파라미터 `void`는 생략 가능
 *    int sub2 = reduce(vi.begin(), vi.end(), 0, minus{});
 *
 *   cout << endl << mul1 << ' ' << mul2 << endl << sub1 << ' ' << sub2;
 */

// https://en.cppreference.com/w/cpp/utility/functional/multiplies
// std::multiplies - Function object for performing multiplication. Effectively calls operator* on two instances of type T.

// https://en.cppreference.com/w/cpp/utility/functional/minus
// std::minus - Function object for performing subtraction. Effectively calls operator- on two instances of type T.
