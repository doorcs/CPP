#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // ifstream, ofstream은 열었던 파일을 자동으로 닫는다
    ifstream fin;
    fin.exceptions(ios_base::badbit | ios_base::failbit); // 이게 없으면 실패하더라도 에러를 발생시키지 않는다! cout, cin 같은 다른 스트림들도 마찬가지

    try {
        fin.open("config.ini"); // default is ios_base::in
    }
    catch(const ios_base::failure& e){
        cerr << e.what() << endl; // TMI: e.what()의 리턴타입은 const char* (C-style string)
    }
  //catch(const exception& e){ // 이것도 가능
  //catch(...){ // 모든 에러를 잡긴 하지만, `.what()`으로 에러 객체에 대한 정보를 출력할 수 없어서 여기서는 못 쓴다!

    ofstream fout;
    fout.exceptions(ios_base::badbit | ios_base::failbit); // 이게 없으면 실패하더라도 에러를 발생시키지 않는다! cout, cin 같은 다른 스트림들도 마찬가지

    try {
        fout.open("config/config.ini"); // default is ios_base::out
        fout << "This is an example for the exception in C++!" << endl;
    }
    catch(const ios_base::failure& e){
        cerr << e.what() << endl; // TMI: e.what()의 리턴타입은 const char* (C-style string)
    }

    return 0;
}
