#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  /*
  vector<pair<int, int>> vp;
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    vp.push_back({x, y});
  }
  */

  vector<pair<int, int>> vp(N);
  for (auto& [a, b] : vp) cin >> a >> b; // 범위 기반 for문을 입력 처리에도 사용할 수 있다!!!!

  ranges::sort(vp, [](auto a, auto b) {
    if (a.first == b.first) {
      return a.second < b.second;
    }
    return a.first < b.first;
  });

  for (const auto& [a, b] : vp) cout << a << ' ' << b << '\n';
  // for (const auto& it : vp) cout << it.first << ' ' << it.second << '\n';
}

// 일차원 벡터일 경우:
/*
  int N; cin >> N;

  vector<int> v(N);

  for (auto& it : v) cin >> it;
*/
