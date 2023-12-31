#include <iostream>
using namespace std;

enum COLOR {RED, GREEN, BLUE};

int main() {
    int color{};
    cin >> color;

    switch (color) {
        case RED:
            cout << "It's red light" << endl;
            break;
        case GREEN:
            cout << "It's green light" << endl;
            break;
        default:
            cout << "It's blue light" << endl;
    }
}