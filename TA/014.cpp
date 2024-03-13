#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "# of students:\n";
    int N;
    cin >> N;

    string highest, tmp;
    int curr, tot = 0, max = 0;

    for(int i=0; i<N; i++){
        cout << "name & score of student " << i+1 << ":\n";
        cin >> tmp >> curr;
        tot += curr;

        if(curr > max){
            max = curr;
            highest = tmp;
        }
    }

    cout << "The average score of the students is " << tot/N << '\n';
    cout << "The student with the highest score is " << highest << " with a score of " << max;
}
