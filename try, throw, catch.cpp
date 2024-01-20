#include <iostream>
#include <string>
using namespace std;

int factorial(int n){
    if(n<0) throw to_string(n) + ": 음수입니다.";
    if(n==0) return 1;
    return n * factorial(n-1);
}

int combination(int n, int r){
    int a = factorial(n);
    int b = factorial(r);
    int c = factorial(n-r);

    return a / b / c;
}

int main(){
    int n, r;

    try{
        // throw 123; // 두번째 catch문에 잡힌다
        throw 123.4; // throw하는 에러 객체가 string도 아니고, int도 아니기 때문에 위에 있는 두 catch문에 잡히지 않는다
        while(true){
            cin >> n >> r;
            cout << combination(n, r) << endl;
        }
    }
    catch(const string& e){ // string 에러 객체를 catch
        cout << e << endl;
    }
    catch(int e){ // int 에러 객체를 catch
        cout << e << endl;
    }
    catch(...){ // catch문에 `...`을 쓰면 위에 있는 catch문들에서 잡히지 않은 나머지 모든 예외들을 처리!
        cout << "알 수 없는 에러 발생" << endl;
    }
} // throw된 에러 객체가 어떤 catch문에도 잡히지 않으면 런타임 에러 발생!
