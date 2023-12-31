#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int num{};
    cout << "# of students:" << endl;
    cin >> num;
    
    string name[num];
    int score[num];

    for (int i=0; i<num; i++) {
        cout << "name & score of student " << i+1 << ":" << endl;
        cin >> name[i] >> score[i];
    }

    int avg = 0;
    for (int i=0; i<num; i++) {
        avg += score[i];
    } avg /= num;

    int max = *max_element(score, score+num);
    string max_name = name[max_element(score, score+num)-score];

    cout << "The average score of the students is " << avg << endl;
    cout << "The student with the highest score is " << max_name << " with a score of " << max << endl;
}
