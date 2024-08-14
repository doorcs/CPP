#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  // 가장 단순한 방법:
  vector<int> v1;
  for (int i = 0; i < N; i++) {
      int tmp;
      cin >> tmp;
      v1.push_back(tmp);
  }

  // 더 효율적인 방법:
  vector<int> v2(N);
  for (int i = 0; i < N; i++) cin >> v2[i];

  // 아름다운 방법 (since C++11):
  vector<int> v3(N);
  for (auto& it : v3) cin >> it;

  // for (int i = 0; i < N; i++) cout << vec[i] << ' ';
  // for (const auto& it : vec) cout << it << ' '; // primitive type은 복사 비용이 낮기 때문에 `for (int it : vec)` 처럼 써도 무방함
}
