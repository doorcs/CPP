#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N; // 입력받은 `N`값을 바탕으로 크기가 N인 2차원 벡터를 만들기

    // 많이 사용되는 방법: C-style 배열 생성자를 이용한 VLA(Variable Length Array, gcc에서 지원해주기는 하지만 C++ 표준은 아니다!!)
    vector<int> adj1[N]; // MSVC, ICC에서는 사용할 수 없는 코드. 이식성이 떨어진다

    // C++ 표준을 준수하는 방법 1: 반복문을 통해 N개의 빈 벡터를 push_back
    vector<vector<int>> adj2;
    for(int i=0; i<N; i++) adj2.push_back(vector<int>());

    // C++ 표준을 준수하는 방법 2: assign() 메소드로 벡터 내부를 N개의 빈 벡터로 채워주기
    vector<vector<int>> adj3;
    adj3.assign(N, vector<int>());


///////
/////////  번외: 이런 방식도 가능은 하다
///////


    // 벡터의 resize() 메소드를 사용하는 방법:
    vector<vector<int>> adj4;
    adj4.resize(N);
    for(int i=0; i<N; i++) adj4[i].resize(0); // resize() 메서드는 인자를 생략할 수 없는데, 벡터의 기본 생성자는 크기가 0인 벡터를 생성하므로 `resize(0)`을 사용
}
