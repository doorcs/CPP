#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float A, B; // `float`형을 사용하는 것이 문제 요구사항
    cin >> A >> B;

    cout << fixed << setprecision(2)
        << A << " + " << B << " = " << A+B << '\n'
        << A << " - " << B << " = " << A-B << '\n'
        << A << " * " << B << " = " << A*B << '\n'
        << A << " / " << B << " = " << A/B;
}
