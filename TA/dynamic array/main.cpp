#include <iostream>
#include <vector>

int main() {
    int size;
    std::cin >> size; // 배열의 크기 입력받기

    int arr1[size]; // 배열의 크기 자리에 `size`라는 변수를 사용한 VLA
    // VLA는 C++ 표준 문법이 아니지만, g++ 컴파일러는 VLA를 알아서 컴파일 해줍니다....

    // C++ 표준을 준수하려면:

    // sol1: std::vector 컨테이너를 사용
    std::vector<int> arr2(size);

    // sol2: 동적 할당을 사용
    auto arr3 = new int[size];
    delete[] arr3; // `new` 키워드로 동적 할당받은 메모리 해제
}

// C언어는 C99에서 Variable Length Array를 표준으로 받아들였지만, C++에서는 아닙니다

/*

std::vector<int> arr2{size}; 처럼 쓰면, `size`를 0번째 원소로 하는 크기가 1인 벡터를 만듭니다 (원소가 `size` 하나인 initializer_list)
std::vector<int> arr2[size]; 처럼 쓰면, 빈 벡터를 `size`개 가지는 2차원 벡터를 만듭니다 (빈 벡터를 만드는 `std::vector<int> arr2;` 문법에 VLA가 붙은 꼴)

 */
