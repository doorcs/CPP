#include <iostream>
#include <string>
#include <vector>
#include <cctype> // isalnum()을 사용하기 위해 필요
using namespace std;

class StringSplitter{
// typedef StringSplitter self;
public:
    StringSplitter(string myString=""): myString(myString) { }
    
    StringSplitter& trim();
  //self& trim();
    StringSplitter& removeNonAlnum();
  //self& removeNonAlnum();
    vector<string> split(char);
private:
    string myString;
};
