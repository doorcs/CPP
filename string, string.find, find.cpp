#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    std::basic_string<char> s1 = "hello"; // 1  |  이걸 typedef한게 std::string !!
    std::string s2 = "hello";             // 2
    auto s3 = "hello"s;                   // 3  |  문자열 뒤에 s를 붙여 C++ style 문자열임을 알려줌
    auto s4 = "hello";                    /* 4  |  C style 문자열                                  */
    // 1, 2, 3은 같은 타입이지만
    /* 4는 다른 타입이다!! (C style 문자열) */
    cout << sizeof(s1) << ' ' << sizeof(s2) << ' ' << sizeof(s3) << ' ' << sizeof(s4) << endl;
    //        24,                  24,                  24,                   4

    string str = "hello";
    auto find1 = str.find('l'); // string에서의 index가 저장됨. 여러개라면 처음 만나는 값의 index !!!!!
    auto find2 = str.find('h', 1); // 두번째 인자로 검색을 시작할 인덱스를 지정해줄 수 있음
    // 이때 값을 찾지 못하면 str::npos를 반환. 

    if(find1 != string::npos) cout << find1 << endl; // 첫번째 l의 index인 2가 출력됨
    if(find2 == string::npos) cout << "cant find!"; // 출력됨 (인덱스 1부터 검색하므로 `h`를 찾을 수 없음!)
    cout << '\n';

    auto find3 = find(begin(str), end(str), 'o');
    // <algorithm> 헤더의 find 함수. 시작&끝 이터레이터를 받고 반환값도 이터레이터. str.find처럼 여러개라면 첫 index !!
    if(find3 != end(str)) cout << distance(begin(str), find3) << endl; // 문자열 시작에서 'o'까지 4hops이므로 4 출력
}
