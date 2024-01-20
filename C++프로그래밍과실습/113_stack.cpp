#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s;
    int elem;
    string cmd;

    for (int i = 0; i < n; i++) {
        cin >> cmd;

        if (cmd == "push") {
            cin >> elem;
            s.push(elem); // `push_back()`이 아니라 그냥 `push()`
        }

        else if (cmd == "pop") {
            if (s.empty()) cout << -1 << endl;
            else {
                cout << s.top() << endl;  // std::stack의 `pop()`은 반환값이 없기 때문에,
                s.pop();                  // 맨 위에 있는 값을 가져오려면 `top()`을 먼저 수행하고 `pop()`!!
            }
        }

        else if (cmd == "size") { cout << s.size() << endl; } // 기본 size()로 구현가능

        else if (cmd == "empty") { cout << s.empty() << endl; } // 기본 empty()로 구현가능
    }
}
