#include <iostream>
#include <vector>

using namespace std;

int arr1[54][54]; // 전역 변수로 선언해두면 모두 0으로 초기화

int main() {
  int arr2[54][54] = {0, }; // 값을 지정하지 않은 원소들은 기본적으로 0으로 초기화

  vector<vector<int>> arr3(54, vector<int>(54, 0)); // 벡터를 활용해 이차원 배열을 만들고 모두 0으로 초기화

  // vector<T>(size_t count, T& value=T()); 생성자를 활용하기 때문에, vector<vector<int>> arr(54, vector<int>(54)) 처럼만 써도 0으로 초기화됨 ( T의 기본 생성자가 호출되므로 )
}
