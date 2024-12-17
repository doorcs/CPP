#include <iostream>
#include <string>
#include <iomanip> // until C++17 ( std::setprecision() )
#include <format> // C++20 ( std::format() )

int main() {
  double val1 = 3.14159265358979;
  int val2 = 4;

  // (until C++17) val2를 소수점 아래 두자리까지만 출력하려면:
  // std::cout << std::fixed << std::setprecision(2) << val1;

  // C++20부터는 std::format() 함수를 활용할 수 있다:
  std::cout << std::format("{:.2f}", val1) << '\n';

  // 앞뒤로 다른 문자열을 넣을 수도 있고, 여러 변수를 포매팅할 수도 있다:
  auto str = std::format("val1 is {:.6f},\nval2 is {}", val1, val2);
  // `{:.6f}`를 하게 되면 소수점 아래 6자리까지만 저장하는데, 소수점 아래 7자리에서 반올림하기 때문에 `3.141592`가 아니라 `3.141593`이 저장된다!!!!
  std::cout << str << '\n'; // 이때 변수 str의 타입은 std::string!
}
