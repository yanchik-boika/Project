#ifndef Order_hpp
#define Order_hpp

#include "Client.hpp"
#include "Product.hpp"
#include <string>



 class Order{
 private:
     std::string product;
     int count;
     double vatRate;
     double price;
     std::string orderDate;
     double orderValue;
     //PaymentMethod paymentMethod;
     std::string paymentMethod;

 public:
     Order(const std::string& product, int count, double vatRate,
           double price, const std::string& orderDate,
           double orderValue, std::string& paymentMethod); 
     std::string getProduct();
     int getCount();
     double getVatRate();
     double getPrice();
     std::string getOrderDate();
     double getOrderValue();
     std::string getPaymentMethod();

 };


#endif /* Order_hpp */
