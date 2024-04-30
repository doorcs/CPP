#include <numeric>
#include <iostream>
#include <vector>
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

/*
 * https://en.cppreference.com/w/cpp/algorithm/reduce
 * Notes - std::reduce behaves like std::accumulate except the elements of the range may be grouped and rearranged in arbitrary order.
 */
