#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int row, col = 0;
    cin >> row >> col;

    int arr[row][col];

    for (int i=0; i<row; ++i)
        for (int j=0; j<col; ++j)
            cin >> arr[i][j];

    for (int i=0; i<row; ++i) {
        int tmp = 0;
        for (int j = 0; j < col; j++)
            tmp += arr[i][j];
        cout << tmp << " ";
    }

    cout << "\n";
    for (int j=0; j<col; ++j) {
        int tmp = 0;
        for(int i=0; i<row; ++i)
            tmp += arr[i][j];
        cout << tmp << " ";
    }
}