#include <iostream>
using namespace std;

int main() {
    int SIZE{};
    cin >> SIZE;

    int *arr = new int[SIZE];
    for(int i=0; i<SIZE; i++) {
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }
    int idx;
    cin >> idx;
    cout << arr[arr[idx]] << '\n';
    delete[] arr;
}
