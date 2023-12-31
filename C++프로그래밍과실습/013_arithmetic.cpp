#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float a, b = 0;
    cin >> a >> b;

    cout << fixed << setprecision(2);
    cout << a << " + " << b << " = " << a+b << endl;
    cout << a << " - " << b << " = " << a-b << endl;
    cout << a << " * " << b << " = " << a*b << endl;
    cout << a << " / " << b << " = " << a/b << endl;
}