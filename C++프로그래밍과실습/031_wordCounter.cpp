#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <regex>
#include <string>
using namespace std;

int main() {
    map<string, size_t> words;
    string in;
    while(cin >> in && in != "^"){
        in = regex_replace(in, regex("[.|,|:|;]"), "");
        for_each(in.begin(), in.end(), [](auto& it){if (static_cast<int>(it) >= 65 && static_cast<int>(it) <= 90) it = static_cast<int>(it) + 32;}); // 소문자로 변환. 'A' = 65, 'a' = 97
        auto search = words.find(in);
        if(search != words.end()) words[in]++;
        else words.insert(make_pair(in, 1));
    }

    cout << "#Words: " << words.size() << endl;
    vector<pair<string, size_t>> v = {words.begin(), words.end()};
    sort(v.begin(), v.end(), [](auto a, auto b){ if (a.second == b.second) return a.first < b.first; return a.second > b.second; }); // 빈도가 큰 pair가 앞으로 오도록 정렬
    cout << "Top 5 Word Frequencies" << endl;

    for(int i=0; i<5; i++){
        cout << i+1 << ' ' << v[i].first << ": " << v[i].second << endl;
    }
    cout << "Find Word Frequencies" << endl;
    while(cin >> in && in != "QUIT"){
        for_each(in.begin(), in.end(), [](auto& it){if (static_cast<int>(it) >= 65 && static_cast<int>(it) <= 90) it = static_cast<int>(it) + 32;});
        auto search = words.find(in);
        if(search == words.end()) cout << in << ": 0" << endl;
        else cout << in << ": " << words[in] << endl;
    }
    cout << endl << "Bye!";
}
