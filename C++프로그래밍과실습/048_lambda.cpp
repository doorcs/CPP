#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> vec;
    std::generate_n(std::back_inserter(vec), n, [] () {return *(std::istream_iterator<int>{std::cin}); });
    copy_if (vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "), [=](int a){return x > a;});
}
