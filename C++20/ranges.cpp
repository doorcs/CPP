// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// namespace ran = std::ranges; // `using namespace std;` 뒤라 `namespace ran = ranges;`처럼 쓸 수도 있지만...

#include <bits/stdc++.h>
namespace ran = std::ranges; // 좋은 줄임말이 없을까 고민하다가, integer를 int로 줄여 쓰는 것에서 영감을 받아 `ran`을 써 봤습니다

int main() {
    std::vector<int> vi1{3, 1, 9999, 5};

    std::vector<int> vi2(4);

    ran::copy(vi1, vi2.begin()); // std::ranges::copy(); 보다는 훨-씬 봐 줄 만한 듯
    // std::copy(vi1.begin(), vi1.end(), vi2.begin());

    ran::sort(vi2, [](const auto& a, const auto& b){
        return a > b;
    });
    // std::sort(vi2.begin(), vi2.end(), [](){;});

    for(const auto& it : vi2) std::cout << it << ' ';
}

/* 
 * `C++20`의 핵심은 ranges 라이브러리인데, 기존(C++17까지)의 C++과는 달라도 정말 너무 다른것같다. 특히! `ranges::` prefix가 너무 길어서 보기 싫다......
 * C++를 사용하는 실제 업무 환경에서는 당연히 `using namespace std;`를 안 쓸 테니 `std::ranges::sort()`같은 호출이 덜 이상할 것 같은데,
 * ICPC같은 프로그래밍 대회나 코딩 테스트 환경처럼 `using namespace std;`로 std 네임스페이스를 가져와서 쓰는게 일반적인 환경에서는 (LeetCode에는 기본적으로 `#include <bits/stdc++.h>`, `using namespace std;`가 적용되어 있다)
 * `sort(begin, end);` 같은 호출보다 `ranges::sort(CONTAINER);` 같은 호출이 `더 좋은` 호출이라고 해도 오히려 타이핑이 더 늘어나고, (주관적) 코드도 못생겨지기 때문에
 * 그냥 지금까지 잘 써오던, 익숙한 {begin, end} 이터레이터 호출을 쓰려고 하지 않을까? 애초에 대부분의 사람들은 <ranges> 라이브러리를 접해 볼 기회도 없을 것 같다
 * 아직까지는 C++17 환경이 조금 남아있을지 몰라도, 빠른 시일 내에 코딩 테스트 환경도 전부 C++20 환경으로 바뀔 것이다
 * 의식적으로 ranges 라이브러리를 사용하도록 해 보자! 맨 위에 `namespace ran = std::ranges` 써 두고, 가능하다면 `ran::`을 사용해봐야겠다
 *
 * +++ 2024.04.17 기준 LeetCode에서는 맨 위에 `namespace ran = std::ranges;` 써두고 STL 알고리즘들을 `ran::` 붙여서 호출할 수 있는 것 확인함 (ran::sort(); 처럼!)
 */
