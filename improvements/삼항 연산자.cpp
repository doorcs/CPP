#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    auto res = (a>b ? a : b);
    // `조건식` ? `참일 때의 값` : `거짓일 때의 값`

    cout << res << '\n';
}

// 삼항 연산자`?:`와 할당 연산자`=`는 연산자 우선순위가 같기 때문에, 삼항 연산자 부분을 반드시 괄호로 감싸줘야 한다!!
// +=, -=, /=, %= 등도 모두 할당 연산자와 우선순위가 같다
