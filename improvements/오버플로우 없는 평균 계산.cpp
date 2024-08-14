#include <iostream>

int main() {
  int lo = 1, hi = 2'147'483'647;

  int fool = (lo+hi) / 2; // 오버플로우 발생!!

  int mid = lo + (hi-lo)/2; // `(lo + hi) / 2` 와 논리적으로 같지만, 오버플로우를 방지할 수 있음!

  std::cout << fool << ' ' << mid;
}

/* 내가 쓰는 변수명:

int fr = 1, rr = 2'147'483'647;

int mid = fr + (rr-fr)/2;

*/
