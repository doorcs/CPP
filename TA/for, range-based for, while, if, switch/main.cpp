#include <iostream>
#include <vector>

constexpr int REP = 3; // `const` 키워드와 비슷하지만, 컴파일 타임에 값이 바인딩됨! `#define REP 3` 같은 매크로 상수를 대체할 수 있는 문법 (C++11)

std::vector<int> vi{1, 3, 5, 7, 9, 2, 4}; // `initializer_list`를 활용한 초기화 (initializer_list에 대해서는 나중에 배웁니다)

int main() {
    for (int i = 0; i < REP; i++) { // for문 `for (초기화식; 조건식; 증감식) { }`
        std::cout << "this is " << i + 1 << " th iteration" << std::endl;
    }

    for (size_t i = 0; i < vi.size(); i++) { // 조건식에서 벡터의 크기를 사용
        std::cout << "element of " << i << "th index is: " << vi[i] << std::endl;
    }

    for (int it : vi) { // 범위 기반 for문 (C++11) `for (루프 변수 : 범위) { }`
        std::cout << it << ' ';
    } std::cout << std::endl;

    for (const auto& it : vi) { // 루프 변수에 여러가지 한정자와 auto 타입 사용 가능!
        std::cout << it << ' ';
    } std::cout << std::endl;

    int cnt = 0;
    while (true) { // while문 `while (조건식) { }`
        if (cnt > 5) { // if문 `if (조건식) { }`
            std::cout << "repeated " << cnt << " times. BREAK\n";
            break; // `break;`는 현재 루프를 탈출합니다 ( for문에서도 사용 가능 )
        }
        std::cout << "this is while loop\n";
        cnt++;
    }

    char ch;
    std::cin >> ch; // 사용자 입력을 char 자료형 변수 ch에 저장
    switch (ch) { // switch문 `switch (식) { case 값: {} case 값: {} default:{} }`
        case 'a':
            std::cout << "input was a\n";
            break; // 이 `break;`가 없으면 아래로 계속 진행됨!!!!!!!!
        case 'b':
            std::cout << "input was b\n";
            break;
        case 'c':
            std::cout << "input was c\n";
            break;
        default: // optional, 써 주는게 좋은 코드!
            std::cout << "input character was not `a || b || c`\n";
    }
}
