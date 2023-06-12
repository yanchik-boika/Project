#ifndef ShopApp_hpp
#define ShopApp_hpp

#include <stdio.h>

#include <stdio.h>

 #include <stdio.h>
 #include <vector>
 #include <map>
 #include "Client.hpp"

 class ShopApp : public Client{
 public:
     int takeUserCount();
     void run();
     void menu();
     void loadClientFromFile(std::vector<Client>& clients, int userCount);
     void addClientToTekstFile(const std::vector<Client>& clients);
     void addClientsToBinaryFile(const std::vector<Client>& clients);
     void newUserCreator(std::vector<Client>& clients);


 };



#endif /* ShopApp_hpp */
