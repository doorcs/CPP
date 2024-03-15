#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "# of students:\n"; // 문자열을 출력할 때 이스케이프 시퀀스도 같이 출력할 수 있습니다. cout << "SomeString" << '\n'; 대신 cout << "SomeString\n";
    int N; // 아래 값들과 함께 한줄로 초기화할 수 있지만, 가독성을 위해 코드 흐름에 맞춰 분리
    cin >> N;

    string highest, tmp;
    int curr, tot = 0, max = 0; // 지역변수를 초기화하지 않으면 쓰레기 값이 들어가기 때문에 원하는 대로 동작하지 않을 수 있습니다

    for(int i=0; i<N; i++){
        cout << "name & score of student " << i+1 << ":\n";
        cin >> tmp >> curr;
        tot += curr;

        if(curr > max){
            max = curr;
            highest = tmp;
        }
    }

    cout << "The average score of the students is " << tot/N << '\n'
        << "The student with the highest score is " << highest << " with a score of " << max;
}
