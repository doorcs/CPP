#include "056_thisPointer.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype> // isalnum()
#include <algorithm>
using namespace std;

StringSplitter& StringSplitter::trim(){
    myString.erase(0, myString.find_first_not_of(" "));
    myString.erase(myString.find_last_not_of(" ")+1);
    return *this;
}

StringSplitter& StringSplitter::removeNonAlnum(){
    string tmp = "";
    for(auto& it: myString){
        if(isalnum(it) || it == ' ') tmp += it;
    }
    // for_each(myString.begin(), myString.end(), [&tmp](auto it){ if(isalnum(it) || it == ' ') tmp += it; });
    myString = tmp;
    return *this;
}

vector<string> StringSplitter::split(char a){ // 어떤 문자를 기준으로 split할지를 인자로 받은 뒤 split 수행
    vector<string> ret; // split 후에 생기는 substring들을 저장할 벡터
    int pos = 0; // position을 0으로 초기화
    
    while ((pos = myString.find(a)) != string::npos){ // string의 `find(char 또는 string)` 메소드는 찾는 값이 string에서 몇번째 index에 있는지를 리턴. 이때 찾는 값이 string에 없으면 `string::npos`를 반환
        ret.push_back(myString.substr(0, pos)); // string의 0번째 index부터 찾는 값 전까지(마지막 index는 exclusive!)를 벡터에 push
        myString.erase(0, pos+1); // string의 0번째 index부터 찾는 값까지를 erase
    }
    ret.push_back(myString); // 더 이상 string에 찾는 값이 없어서 while loop을 빠져나왔을 때, string에 마지막으로 남아있는 문자열을 벡터에 push

    return ret; // split된 string들이 들어있는 벡터를 리턴
}
