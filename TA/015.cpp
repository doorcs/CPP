#include <iostream>
// #include <vector>
using namespace std;

int main() {
    int SIZE;
    cin >> SIZE; // 배열의 크기 입력받기

    int* arr = new int[SIZE]; // 동적 할당을 사용
    for(int i=0; i<SIZE; i++) cin >> arr[i];

//  vector<int> arr(SIZE);
//  for(int i=0; i<SIZE; i++) cin >> arr[i]; // 직접 동적 할당과 해제를 처리하는 대신 벡터를 사용할 경우의 코드

    int idx;
    cin >> idx;
    cout << arr[arr[idx]]; // 문제 요구사항
    delete[] arr;
}
