#include <algorithm>
#include <iostream>
#include <vector>
#include <ranges> // C++20

int main() {
    std::vector<int> vi{3, 6, 6, 7, 9, 9, 8, 3, 6};

    std::ranges::sort(vi); // unique() 사용 전에는 반드시 컨테이너를 정렬해줘야 함!
    auto [fr, rr] = std::ranges::unique(vi); // `std::ranges::unique()`는 `std::unique()`같은 작업을 수행한 다음 `std::ranges::subrange` 객체를 리턴함!
    vi.erase(fr, rr); // .erase()는 벡터 컨테이너의 메소드이기 때문에  `using namespace std;`가 없어도 `std::` prefix가 붙지 않는다.
    for (const auto& it : vi) std::cout << it << '\n';

/*
 * until C++17:

    std::sort(vi.begin(), vi.end());
    vi.erase(std::unique(vi.begin(), vi.end()), vi.end()); // erase-remove 관용구와 비슷한 형태의 erase-unique 관용구
    // for (size_t i = 0; i < vi.size(); i++) std::cout << vi[i] << '\n'; // C++11 이전 버전에서도 사용 가능한 일반 반복문
    for (const auto& it : vi) std::cout << it << '\n';
 */
}

// 컨테이너를 파라미터로 받는 `std::ranges::` 네임스페이스의 알고리즘들에 대해:
/*
 * std::ranges::sort(CONTAINER); 이런 방식의 호출은 자동으로 아래 형태로 변환되어 처리된다:
 * std::ranges::sort(ranges::begin(CONTAINER), ranges::end(CONTAINER));
 *
 * 즉, 파라미터로 받은 컨테이너를 다시 ranges::begin(), ranges::end()의 파라미터로 사용해 처리함!!!
 */

// `std::ranges::subrange`에 대해:
/*
 * https://en.cppreference.com/w/cpp/ranges/subrange
 * The subrange class template combines together an iterator and a sentinel into a single view.

    `std::ranges::subrange`는 `.begin()`, `.end()`, `.size()`, `.empty()` 등의 메소드들을 지원함!
 */
