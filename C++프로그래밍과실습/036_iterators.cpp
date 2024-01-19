// std::istream_iterator, ostream_iterator 를 이용해 for문 없는 콘솔 입출력을 연습해 봅니다.
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    istream_iterator<int> cin_iter(cin);
    istream_iterator<int> eos;
    ostream_iterator<int> cout_iter(cout, " ");

    copy(cin_iter, eos, back_inserter(v));
    sort(v.begin(), v.end());
    copy(v.begin(), v.end(), cout_iter);
}
