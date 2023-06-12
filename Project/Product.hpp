#ifndef Product_hpp
#define Product_hpp
#include <string>

#include <string>

class Product {
public:
    Product(const std::string& name, double price, double vatRate,
            int quantity);

    std::string getProductName() const;
    double getPrice() const;
    double getVatRate() const;
    int getQuantity() const;

private:
    std::string productName;
    double price;
    double vatRate;
    int quantity;
};





#endif /* Product_hpp */
