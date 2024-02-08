#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    auto res = (a>b)? a : b; // (`조건식`) ? `참일 때의 값` : `거짓일 때의 값`;

    cout << res << '\n';
}
