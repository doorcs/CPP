#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;

    for(int i=0; i<a; i++){
        cout << "총" << ' ' << a << "번" << ' ' << "중" << ' ' << i+1 << "번째" << ' ' << "출력" << endl;
    }

    for(int i=0; i<a; i++){
        cout << "총 " << a << "번 중 " << i+1 << "번째 출력" << '\n'; // '\n'은 불필요한 버퍼 플러쉬가 없어 endl보다 빠르다. endl == '\n' + buffer flush
    }

    for(int i=0; i<a; i++){
        cout << "총 " << a << "번 중 " << i+1 << "번째 출력\n"; // 문자열을 출력할 때 문자열 중간에 공백을 넣을 수 있는것처럼 이스케이프 시퀀스(\n, \t 등등)도 넣을 수 있다!! 
    }
}
