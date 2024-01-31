#include <iostream>
using namespace std;

int main() {
    // 입력받은 N이 홀수인지 짝수인지 판단하려고 함
    int N;
    if(!(cin >> N) or N <= 0) return 0; // `입력값이 int형이 아닐 경우(cin이 false를 반환) || N이 0 이하일 경우` 예외 처리

    // 방법 1: 모듈로 연산을 이용 (나머지를 활용)
    if(N % 2) cout << "홀수!\n";
//  if(N % 2 == 1) cout << "홀수!\n"; 와 같다
    else cout << "짝수!\n";

    // 방법 2: 비트 and 연산을 이용 (2진수 표현, 비트 표현의 LSB를 활용)
    if(N & 1) cout << "홀수!\n";
//  if(N & 1 == 1) cout << "홀수!\n" 와 같다
    else cout << "짝수!\n";
}
