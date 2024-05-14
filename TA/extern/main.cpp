#include <iostream>
#include <vector>

// extern {자료형} 변수명;
extern std::vector<int> vi; // 다른 소스 파일(헤더XX)에서 정의된 전역 변수를 `선언`

// 함수는 묵시적으로 extern이기 때문에 extern을 생략할 수 있습니다:
bool isVectorEmpty(std::vector<int>& vec); // 다른 소스파일에서 정의된 함수를 `선언`

// extern bool ret;
// 지역변수는 extern 키워드로 가져올 수 없습니다!

int main() {
	for(auto it: vi) std::cout << it << ' '; // main.cpp에서는 벡터를 선언

	if(!isVectorEmpty(vi)) std::cout << '\n' << "This vector is NOT empty";

	// std::cout << '\n' << ret;
    // invalid
}
