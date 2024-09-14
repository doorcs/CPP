#include <iostream>

// C++ 함수의 구조:
// `리턴타입` `함수명`(`파`라`미`터`들`) { `함수 본체` };
void printHello() { // 리턴값이 없는 함수는 리턴 타입이 `void`
    std::cout << "Hello\n";
    return;
}

bool returnTrue() {
    return true;
}

void printHelloNtimes(int N) {
    for (int i = 0; i < N; i++) std::cout << "Hello!\n";
    // 리턴 타입이 void인 함수는 return 생략 가능
}

const char* returnHello(); // 함수의 선언과 정의를 분리할 수도 있음 ( `returnHello()` 함수 선언! )

int main() {
    printHello();
    bool cond = returnTrue(); // 함수가 return하는 값을 변수에 할당

    if (cond) {
        int rep = 3;
        printHelloNtimes(rep);
    }

    std::cout << returnHello();
}

const char* returnHello() { // `returnHello()` 함수 정의
    return "Hello!!!";
}
