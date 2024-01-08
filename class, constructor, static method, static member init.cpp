#include <iostream>
using namespace std;

//int idCounter = 1; // 클래스와 관련된 변수는 전역변수로 선언하는 대신 클래스 안에서 static 변수로 선언할 수 있다!

class Color{
public:
    Color() : r(0), g(0), b(0), id(idCounter++) /*id 필드에 idCounter 값이 들어간 다음 ++가 수행된다 */ { } // 기본 생성자. 0, 0, 0 초기화
    Color(float r, float g, float b) : r(r), g(g), b(b), id(idCounter++) { } // 생성자 오버로딩 with 초기화 리스트

    // Color(float r=0, float g=0, float b=0) : r(r), g(g), b(b) {} 위의 두 생성자를 하나로 합친 것
    // 초기화 리스트를 사용할 때, 기본값을 설정해줄 수도 있다. 매개변수가 비었을 때 0, 0, 0 초기화 생성자처럼 동작

    float getR() { return r; }
    float getG() { return g; }
    float getB() { return b; }

    static Color MixColors(Color a, Color b){ // 함수를 클래스의 static 멤버 메소드로 선언 && 정의
        return Color((a.r + b.r)/2, (a.g + b.g)/2, (a.b + b.b)/2);
    } // static 멤버 함수(메소드)의 가장 큰 장점은 * 클래스의 private field에 있는 멤버에도 직접 접근할 수 있다는것! *
    // = 게터를 안 써도 된다!!
    // return Color((a.getR()+b.getR())/2, (a.getG()+b.getG())/2, (a.getB()+b.getB())/2); 처럼 쓰지 않아도 됨

    int getId(){return id;}
    static int returnIdCounter(){return idCounter;}

private:
    float r;
    float g;
    float b;

    int id;
    static int idCounter;
    // static int idCounter = 1; 처럼은 쓸 수 없다!! static 멤버 변수는 클래스 밖에서 초기화해줘야 한다
    // static 멤버는 각각의 객체가 아니라, 클래스 그 자체와 관련된 것이기 때문!
};

int Color::idCounter = 1; // 클래스의 static 멤버 변수 초기화. Color라는 클래스 이름이 일종의 namespace 역할을 하는 것
// 이때 static 멤버 변수가 private 영역에 있더라도 초기화해줄 수 있다.
// 정적 멤버변수 초기화는 접근제어 규칙(public, private)의 예외!!!

int main() {
    cout << Color::returnIdCounter() << endl; // 현재 idCounter 값 == 1
    Color Red(1, 0, 0);
    cout << Red.getId() << endl; // Red 객체의 id에 할당된 값 == 1
    // idCounter 값이 1 증가함(idCounter++)

    cout << Color::returnIdCounter() << endl; // 현재 idCounter 값 == 2
    Color Blue(0, 0, 1);
    cout << Blue.getId() << endl; // Blue 객체의 id에 할당된 값 == 2
    // idCounter 값이 1 증가함(idCounter++)

    cout << Color::returnIdCounter() << endl; // 현재 idCounter 값 == 3

    // Color Mixed = MixColors(Red, Blue);
    Color Mixed = Color::MixColors(Red, Blue); // Color라는 클래스 이름이 namespace 역할
    cout << Mixed.getR() << ' ' << Mixed.getG() << ' ' << Mixed.getB() << endl;
    cout << Red.getId() << ' ' << Blue.getId() << ' ' << Mixed.getId() << endl;
}


// MixColors를 Color 클래스의 메소드가 아닌 별도 함수로 구현할 경우:

// Color MixColors(Color a, Color b){
//     // Color res =  Color((a.getR() + b.getR()) / 2, (a.getG() + b.getG())/2, (a.getB() + b.getB())/2);
//     // return res;
//     return Color((a.getR() + b.getR()) / 2, (a.getG() + b.getG())/2, (a.getB() + b.getB())/2);
// }
