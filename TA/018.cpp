#include <iostream>
#include <string>
using namespace std;

void my_swap(int &m, int &n){
    (m ^= n), (n ^= m), (m ^= n); // XOR 연산을 활용한 swap
  // m += n; n = m-n; m = m-n; // 덧셈과 뺄셈을 활용한 swap
  // int tmp = m; m = n; n = tmp; // 임시 변수를 활용한 swap
}

int main() {
    int m, n;
    cin >> m >> n;

    my_swap(m, n);

    cout << m << " " << n;
}
