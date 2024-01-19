#include "052_cart_cart.h"
#include "052_cart_item.h"
#include <iostream>
#include <algorithm>
using namespace std;

void Cart::addItem(const Item &item) {
    items.push_back(item);
}
void Cart::deleteItem(int id) {
    items.erase(remove_if(items.begin(), items.end(), [id](auto a){return a.getId() == id;}), items.end());
}
int Cart::checkout() {
    Checkout tmp;
    return tmp.calculateTotalPrice(items.begin(), items.end());
}
void Cart::viewItemDetails(int id, std::ostream &out) const {
    auto it = find_if(items.begin(), items.end(), [id](auto a){return a.getId() == id;});
    if(it != items.end()){
        out << "Item " << id << ": " <<endl;
        out << "Name: " << it->getName() << endl;
        out << "Quantity: " << it->getQuantity() << endl;
        out << "Price: " << it->getPrice() << endl;
    }
    else out << "Item not found." << endl;
}

// const_iterator Cart::cbegin() const {}
// const_iterator Cart::cend() const {}
