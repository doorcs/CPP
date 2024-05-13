#include <vector>

std::vector<int> vi{3, 6, 9}; // int 자료형을 담는 std::vector인 `vi`를 `전역 변수`로 정의

bool isVectorEmpty(std::vector<int>& vec){ // bool 자료형을 반환하는 함수 `isVecrtorEmpty()` 정의
    bool ret = (vec.empty() ? true : false); // 함수 내부에서 bool 자료형 `ret`을 `지역 변수`로 정의
    return ret;
}

// 삼항(ternary) 연산자와 할당(assign) 연산자는 우선순위가 같기 때문에 반드시 삼항 연산자 부분을 괄호로 감싸주기!!!
