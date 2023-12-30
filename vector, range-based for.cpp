#include <iostream>
#include <vector>
using namespace std;

int main() {
/* for문 */
    for(int i=0; i<N; i++) { /* 중괄호는 복합문! 여러 statement를 묶어주는 것 */
        statement_1;
        statement_2;
    }

    for(int i=0; i<N; i++)
        statement_3; /* 실행할 statement가 한줄이면 중괄호로 안 감싸도 된다 */

    for(int i{}; i<N; i*2){} // 증감식 부분에 expression을 넣어버리면 무한루프가 된다!!

    for(int i{}; i<N; i*=2){}
    for(int i{}; i<N; i=i*2){} // statement를 쓰기!
//

/* 벡터, 범위기반 for문 */
    vector<int> v1(3, 0); // (크기, 초기화값)
    vector<int> v2{1, 2, 3}; // brace init, 중괄호 초기화. C++11부터 도입, 모든 변수에 동일하게 적용할 수 있는 초기화 방법

    for(int i=0/*int i{}로도 0으로 초기화 가능*/; i<v1.size(); i++) cout << v1[i];
    cout << endl;

    // range-based for, 범위기반 for문
    for(int iter: v2) cout << iter;
    cout << endl;
    // for(컨테이너의_자료형 임시변수명: 컨테이너명){}
    // for(auto iter: container){} 처럼 자료형 자리에 auto를 쓸 수 있다

/* 컨테이너 속 요소들 참조하기 */
    cout << v2.front() << v2.back() << endl; // v.front(), v.back() 사용해서 요소에 접근 가능.
    cout << v2[0] << v2[v2.size() - 1] << endl; // 인덱스를 이용해 값을 참조할 수도 있음!

    cout << v2[v2.size()]; // 이렇게 쓰면 안되는 이유?
    // 벡터의 v.size(), 스트링의 s.size()와 s.length()는 모두 크기를 반환하는데,
    // 인덱스는 0부터 시작하기 때문에 인덱스를 통해 마지막 요소를 참조할 땐 size()-1을 사용해야한다!!!!!!!!

    cout << *v2.begin() << *(v2.end()-1) << endl;
    // iterator는 일반화된 포인터. 따라서 이터레이터에 역참조 연산(derefrence)을 하면 값에 접근할 수 있다.
    // 이때 v.end()는 벡터의 마지막 주소를 반환하기 때문에, 마지막 요소를 참조하려면 -1을 해줘야한다!!
}
