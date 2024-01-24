#include <iostream>
#include <iomanip> // setw(), setprecision()
#include <memory>
using namespace std;

template <typename T>
class Test{
    T* data;
public:
    Test(): data(new T){
        cout << setw(43) << "Constructor" << endl; // setw()는 포매팅해서 출력하려는 문자열 왼쪽에 써줘야한다! // set width
    }
    ~Test() noexcept{
        delete data;
        cout << setw(43) << "Destructor" << endl;
    }
};

int main(){
    cout << "=============================== main() begins =================================" << endl;
    cout << "======================== create unique_ptr<Test> `a` ==========================" << endl;
    unique_ptr<Test<int>> a(new Test<int>());
    cout << "==== unique_ptr<Test> `b` takeover the ownership from unique_ptr<Test> `a` ====" << endl;
    unique_ptr<Test<int>> b(a.release());
    cout << "========= unique_ptr<Test> `b` points new data after releasing old one ========" << endl;
    b.reset(new Test<int>());
    cout << "================================ main() ends ==================================" << endl;
}
