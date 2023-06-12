#ifndef ShopApp_hpp
#define ShopApp_hpp

#include <stdio.h>
#include <vector>
 #include <map>
 #include "Client.hpp"
 #include "Product.hpp"
 #include "Order.hpp"

 class ShopApp : public Client{
 public:
    int takeUserCount();
    void run();
    void menu();
    void loadClientFromFile(std::vector<Client>& clients, int userCount);
    void addClientToTekstFile(const std::vector<Client>& clients);
    void addClientsToBinaryFile(const std::vector<Client>& clients);
    void newUserCreator(std::vector<Client>& clients);
     void loadProductFromFile(std::vector<Product>& products);
     void showAvailableProducts(std::vector<Product>& products);
     void showUserList(std::vector<Client>& clients);
     void createOrder(std::vector<Client>& clients, std::vector<Product>& products, std::map<std::string, Order>& orders);

 };

#endif /* ShopApp_hpp */
