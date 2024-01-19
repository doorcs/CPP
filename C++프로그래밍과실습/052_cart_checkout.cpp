#include "052_cart_checkout.h"
using namespace std;

int Checkout::calculateTotalPrice(vector<Item>::const_iterator begin, vector<Item>::const_iterator end) const {
    int sum = 0;
    for(auto& it = begin; it<end; it++){
        sum += it->getPrice() * it->getQuantity();
    }
    if(this->discountCode == DISCOUNT_20) sum *= 4/5;
    else if(this->discountCode == DISCOUNT_50) sum /= 2;

    return sum;
}
void Checkout::setShippingAddress(const std::string &shippingAddress) {
    this->shippingAddress = shippingAddress;
}
void Checkout::setDiscountCode(DiscountCode discountCode) {
    this->discountCode = discountCode;
}
