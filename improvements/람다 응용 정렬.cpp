#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct PairInt{ // C++의 `struct`는 C에서의 `struct`와는 많이 다르지만..
    int first;
    int second;
};

int main() {
    PairInt a = PairInt{3, 4};
    auto b = PairInt{9999, 2};
    PairInt c{5, 2};

    vector<PairInt> vpii{a, b, c};

    // std::sort(first, last, comp);
    sort(vpii.begin(), vpii.end(), [](const auto& a, const auto& b)->bool{ // 지금처럼 컴파일러가 리턴 타입을 추론할 수 있는 경우 `->{return type}`은 생략 가능
        if (a.second == b.second) return a.first < b.first; // second가 같을 경우 first의 오름차순으로 정렬
        else return a.second < b.second; // second가 다를 경우 second의 오름차순으로 정렬
    });
    // 기본 자료형이 아니기 때문에 sort(vpii.begin(), vpii.end()); 처럼은 사용할 수 없다!

    for (const auto& it : vpii) cout << it.first << ' ' << it.second << '\n';
}
