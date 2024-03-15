#include <iostream>
#include <memory>

auto sum(int a, int b){
    return std::tuple{"sum: ", a + b};
}

int main() {
    auto pa = std::make_unique<int>(1); // pa의 자료형은 unique_ptr<int>
    auto pb = std::make_unique<int>(2); // make_unique는 템플릿 함수 (C++14에서 도입)

    std::cout << *pa << ", " << *pb << std::endl;
    auto my_swap = [](auto a, auto b){ auto temp = *a; *a = *b; *b=temp; }; // 람다함수 문법: [](){}: 캡쳐, 파라미터, 함수 본체
    my_swap(pa.get(), pb.get()); // 윗줄에서 정의한 람다함수를 사용
    std::cout << "a: " << *pa << ", b: " << *pb << std::endl;

    auto [label, result] = sum(*pa, *pb); // structural binding (C++17 채신 문법)
    std::cout << label << result << std::endl;

    return 0;
}
