#include "Product.hpp"




Product::Product(const std::string& productName, double price, double vatRate, int quantity)
    : productName(productName), price(price), vatRate(vatRate), quantity(quantity) {
}

std::string Product::getProductName() const{
    return productName;
}

double Product::getPrice() const {
    return price;
}

double Product::getVatRate() const {
    return vatRate;
}

int Product::getQuantity() const{
    return quantity;
}
