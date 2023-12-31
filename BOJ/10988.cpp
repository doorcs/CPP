#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    for (int i=0; i<s.length(); i++){
        if (s[s.length() - 1 - i] != s[i]){ // s.length()는 길이를 반환하는데, 인덱스는 0부터 시작하기때문에 끝에 접근하려면 -1 해줘야함!
            cout << 0;
            return 0;
        }
    }
    cout << 1;
    return 0;
}
