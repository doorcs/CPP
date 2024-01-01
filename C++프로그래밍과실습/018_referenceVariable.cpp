#include <iostream>
#include <string>
using namespace std;

int my_swap(int &m, int &n){
    int tmp = m;
    m = n;
    n = tmp;
}

int main() {
    int m, n;
    cin >> m >> n;
    my_swap(m, n);
    cout << m << " " << n;
}