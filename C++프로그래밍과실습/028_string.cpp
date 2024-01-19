#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>
#include <vector>
using namespace std;

int countCharacter(const std::string &str, char ch)
{
    // implement your code
    int cnt = 0;
    for(int i=0; i<str.length(); i++){
        if(ch == str[i]) cnt++;
    }
    return cnt;
}

void toUpperCase(std::string &str)
{
    // implement your code
    for(auto &it: str) it-=32;
}

bool startsWith(const std::string_view str, const std::string_view prefix)
{
    // implement your code
    int plen = prefix.length();
    string check = "";
    for(int i=0; i<plen; i++){
        check += str[i];
    }
    if(check == prefix) return 1;
    return 0;
}

int main()
{
    std::vector<std::string> words = {"hello", "world", "example"};
    char characterToCount = 'l'; // 문자 l
    for (const auto &word : words) {
        std::cout << "Count of '" << characterToCount << "' in \"" << word << "\": "
        << countCharacter(word, characterToCount) << std::endl;
    }
    std::cout << std::endl;

    for (auto &word : words) {
        toUpperCase(word);
        std::cout << "Modified string: " << word << std::endl;
    }
    std::cout << std::endl;

    std::string_view prefix = "EX";
    for (const auto &word : words) {
        std::cout << "Does \"" << word << "\" start with '" << prefix << "'? "
        << (startsWith(word, prefix) ? "Yes" : "No") << std::endl;
    }

    return 0;
}
