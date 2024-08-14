#include <iostream>

// invalidDeclaration; // 변수를 선언할 때는 반드시 변수명 앞에 타입을 명시해줘야 함!

int globalVar1; // 전역 변수의 경우, 선언만 해도 자료형의 기본값으로 초기화됩니다 ( int: 0 )

int globalVar2 = 123; // 전역 변수를 선언하는 동시에 초기화 (값 할당)

const int CVAR = 456; // 자료형 앞에는 `const`, `static`등의 한정자(qualifier)도 올 수 있음!
static int SVAR{}; // 빈 initializer_list를 사용하면 자료형의 기본값이 할당됩니다 ( int: 0, float: 0.0, std::string: "" )

void hello() { // hello() 함수를 선언과 동시에 정의
    std::cout << "Hello!" << std::endl; // std::cout으로 출력만 하고, 리턴값이 없다
    return; // 이렇게 리턴 값이 없는 함수는 리턴 타입 자리에 `void`를 써 줍니다 ( 12번째 줄 처럼! )
}

const char* hello2(); // hello2() 함수를 선언 (함수의 선언과 정의를 분리)

// main()도 함수입니다. 함수 이름 앞에는 그 함수의 리턴 타입을 적어줘야 합니다 ( main()은 반드시 리턴 타입이 int여야 함! )
int main() { // main() 함수를 선언하는 동시에 정의
    int localVar1; // 지역 변수의 경우, 초기화해주지 않으면 쓰레기 값이 들어갑니다
    int localVar2 = 789; // 지역 변수를 선언하는 동시에 초기화
    int localVar3{}; // 변수를 선언하고 0으로 초기화 (변수에 0을 할당)
    localVar3 = 999; // 변수에 값을 재할당 (변수에 저장된 값: 0 -> 999)

    std::cout << globalVar1 << ' ' << globalVar2 << ' ' << std::endl;
    std::cout << CVAR << ' ' << SVAR << std::endl;
    std::cout << localVar1 << ' ' << localVar2 << ' ' << localVar3 << std::endl;

    hello(); // 리턴 타입이 void인 함수 `hello()` 호출
    std::cout << hello2(); // 리턴 타입이 C-style 문자열(const char *)인 함수 `hello2()`를 호출하고, 반환값을 cout으로 출력

    return 0; // main()함수의 return 0은 프로그램이 정상적으로 종료됐다는 것을 의미함
} // main() 함수의 리턴 타입은 int이지만 `return 0;`은 생략 가능!!!

const char* hello2() { // 함수의 정의 (선언부에서 세미콜론을 떼고, 중괄호를 열어서 함수 본체 내용을 적어주기!)
    return "Hello, Function2!\n";
}

// 사실 `auto main() -> int {}` 처럼 쓸 수도 있긴 하지만....
