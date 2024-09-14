#include <iostream>
// 입력과 출력을 처리하려면 어떻게 해야 할까요?

// C에서는 <stdio.h> 헤더에 정의된 scanf(), printf() 같은 함수를 사용하고,
// Python에서는 input()또는 sys.stdin.readline(), print() 같은 함수를 사용합니다.

// C++에서는 일반적으로 `std::cin`, `std::cout` 객체(클래스의 인스턴스)를 통해 입력과 출력을 처리하는데,
// 이런 입출력 객체를 사용하기 위해서는 프로그램 상단에 <iostream> 헤더를 include 해 줘야 합니다

int main() { // 모든 C++ 프로그램에는 반드시 `main()` 함수가 포함되어 있어야 합니다!!
    // std::cout << "Hello World!\n";

    int A; // int형 변수 `A`를 선언 (초기화되지 않은 지역 변수에는 임의의 값이 들어감)
    int B = 0; // int형 변수 `B`를 선언함과 동시에 0으로 초기화

    std::cin >> A; // == `scanf("%d", &A);`
    std::cin >> B; // == `scanf("%d", &B);`
    // std::cin 객체를 활용한 입력 처리

    std::cout << A + B; // printf("%d", A + B);
    // std::cout 객체를 활용한 출력 처리
}

// int A, B;
// std::cin >> A >> B; // == `scanf("%d %d", &A, &B);`
// std::cout << A + B;
