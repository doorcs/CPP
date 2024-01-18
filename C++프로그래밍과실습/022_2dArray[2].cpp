// 처음 풀었던 방식은 UB(Undefined Behavior)였기 때문에, 포인터와 동적 할당을 사용해 다시 구현해 보았습니다. ( +unique_ptr )

// 기존 코드:
//
// int row, col;
// cin >> row >> col;
// int arr[row][col];
 
#include <iostream>
#include <memory>
using namespace std;

int main() {
    int row, col;
    cin >> row >> col;

    unique_ptr<unique_ptr<int[]>[]> arr(new unique_ptr<int[]>[row]);
    for (int i = 0; i < row; i++) {
        arr[i] = unique_ptr<int[]>(new int[col]); // 동적 할당을 사용한 정상적인 구현
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < row; i++) {
        int tmp = 0;
        for (int j = 0; j < col; j++) {
            tmp += arr[i][j];
        }
        cout << tmp << " ";
    }
    cout << "\n";

    for (int j = 0; j < col; j++) {
        int tmp = 0;
        for (int i = 0; i < row; i++) {
            tmp += arr[i][j];
        }
        cout << tmp << " ";
    }
    cout << "\n";
}
