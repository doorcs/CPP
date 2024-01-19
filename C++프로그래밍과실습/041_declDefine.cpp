// // data.cpp
// #include <vector>

// std::vector vec = {1, 2, 3, 4, 5};
// int total=0;

// extern std::vector<int> vec;
// extern int total;
// // reader.cpp
// #include <vector>

// extern std::vector<int> vec;
// extern int total;

// void sum() {
//     total = 0;
//     for(int it: vec){
//         total += it;
//     }
// }
// //sum.cpp
// #include <iostream>
// #include <vector>

// extern std::vector<int> vec;

// void read() {
//     int len;
//     std::cin >> len;
//     for(int i=0; i<len; i++){
//         int tmp;
//         std::cin >> tmp;
//         vec.push_back(tmp);
//     }
// }
// main.cpp
void read();
void sum();

int main() {
    read();
    sum();
    std::cout << total << std::endl;
    return 0;
}
