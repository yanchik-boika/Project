#include "Order.hpp"

#include <iostream>



 Order::Order(const std::string& product, int count, double vatRate,
           double price, const std::string& orderDate,
           double orderValue, std::string& paymentMethod)
     : product(product),
       count(count),
       vatRate(vatRate),
       price(price),
       orderDate(orderDate),
       orderValue(orderValue),
       paymentMethod(paymentMethod){}


 std::string Order::getProduct(){
     return product;
 }

 int Order::getCount(){
     return count;
 }

 double Order::getVatRate(){
     return vatRate;
 }

 double Order::getPrice(){
     return price;
 }

 std::string Order::getOrderDate(){
     return orderDate;
 }

 double Order::getOrderValue(){
     return orderValue;
 }

 std::string Order::getPaymentMethod(){
     return paymentMethod;
 }
