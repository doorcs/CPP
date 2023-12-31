#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int SIZE;
    cin >> SIZE;

    int arr[SIZE];
    for (int i=0; i<SIZE; ++i)
        cin >> arr[i];

    reverse(arr, arr+SIZE);

    for (int i=0; i<SIZE; ++i)
        cout << arr[i] << " ";
    cout << endl;
}