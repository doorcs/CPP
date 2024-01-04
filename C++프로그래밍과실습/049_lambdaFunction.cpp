#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Item{
    string name;
    double price;
    int quantity;
};

int main() {
    vector<Item> inventory = {
        {"Apple", 0.99, 10},
        {"Banana", 0.59, 20},
        {"Cherry", 1.49, 5},
        {"Dates", 2.99, 2},
        {"Elderberry", 3.99, 0},
        {"Fig", 2.49, 15},
        {"Grape", 0.79, 25},
        {"Honeydew", 1.29, 8},
        {"Indian Gooseberry", 2.99, 0},
        {"Jackfruit", 4.99, 1}
    };
    // implement your code

    // 1. Item.price 순으로 정렬
    // 2. 전체 출력
    // 3. name == "Grape" 인 경우를 찾고, `Item found: 이름 가격 수량` 출력
    // 4. Item.price가 2보다 큰 것의 개수를 찾고, `Number of expensive items: 수량` 출력
    // 5. Item.quantity == 0인 것들을 모두 삭제한 다음 전체 출력

    sort(inventory.begin(), inventory.end(), [](Item a, Item b){ return a.price < b.price; });

    for_each(inventory.begin(), inventory.end(), [](Item a){ cout << a.name << ' ' << a.price << ' ' << a.quantity << endl; });
    
    auto find = find_if(inventory.begin(), inventory.end(), [](Item a){ return a.name == "Grape"; });
    cout << "Item found: " << find->name << ' ' << find->price << ' ' << find->quantity << endl;

    auto cnt = count_if(inventory.begin(), inventory.end(), [](Item a){ return a.price > 2; });
    cout << "Number of expensive items: " << cnt << endl;

    // v.erase(beg, end);
    // remove_if(inventory.begin(), inventory.end(), [](Item a){ return a.quantity == 0; }) // 삭제 + 당겨오기가 끝난 지점의 이터레이터 반환. >> 이후 끝까지 erase 필요!
    inventory.erase(remove_if(inventory.begin(), inventory.end(), [](Item a){ return a.quantity == 0; }), inventory.end());

    for_each(inventory.begin(), inventory.end(), [](Item a){ cout << a.name << ' ' << a.price << ' ' << a.quantity << endl; });
}
