#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;


map<string, string> phonebook;

int main() {
    int rep;
    cin >> rep;

    for(int i=0; i<rep; i++){
        string a, b;
        cin >> a >> b;
        // phonebook.insert(make_pair(a, b)); // 이런 방식도 사용 가능
        phonebook[a] = b; // 파이썬과 비슷한 사용법
    }

    string s;
    while(cin>>s){
        if(s == "QUIT") return 0;

        auto find = phonebook.find(s);
        if(find != phonebook.end()) cout << find->second << endl;
        //                 find->second 대신 phonebook[s]를 쓸 수도 있다
        else cout << "NOT FOUND" << endl;
    }

}
