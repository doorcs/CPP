#include <cassert>
#include <numeric>
#include <iostream>
#include <vector>
#include <list>

// implement your function template:
template<typename T, typename U>
U my_accumulate(T _begin, T _end, U init){
    auto curr = _begin;

    while (curr != _end) init += *curr++;

    return init;
}

// main.cpp 제공
int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    for (const auto& it : vec)
        std::cout << it << ' ';
    std::cout << '\n';
    std::cout << my_accumulate(vec.cbegin(), vec.cend(), 0) << std::endl;
    assert (my_accumulate(vec.cbegin(), vec.cend(), 0) == accumulate(vec.cbegin(), vec.cend(), 0));

    std::list<int> numbers = {1, 2, 3, 4, 5};
    for (const auto& it : numbers)
        std::cout << it << ' ';
    std::cout << '\n';
    std::cout << my_accumulate(numbers.cbegin(), numbers.cend(), 0) << std::endl;
    assert (my_accumulate(numbers.cbegin(), numbers.cend(), 0) == accumulate(numbers.cbegin(), numbers.cend(), 0));

    return 0;
}
