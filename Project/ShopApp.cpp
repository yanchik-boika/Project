#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Client.hpp"
#include "ShopApp.hpp"
#include "Product.hpp"


 using namespace std;

 void ShopApp::menu(){
     cout << endl;
     cout << "---------- Our menu ------------- " << endl
     << "Enter 1, if you want to see our menu one mo time" << endl
     << "Enter 2, if you want to create a new user " << endl
     << "Enter 3, if you want to see our products " << endl
     << "Enter 4, if you want to create an order " << endl
     << "Enter 5, if you want to see client's orders " << endl
     << "Enter 6, if you want to see our clients list " <<  endl
     << "Enter 10, if you want to close our session " << endl;
 }


int ShopApp::takeUserCount(){       // Function to get the number of users
     int userCount = 0;
     fstream userFile;
     userFile.open("/Users/yan.boika/Documents/programming/C++/endProject/users.txt");
     string temp;
     while(getline(userFile, temp)){
         userCount++;
     }
     userFile.close();
     return userCount;
 }

 void ShopApp::loadClientFromFile(vector<Client>& clients, int userCount){
     fstream userFile;
     userFile.open("/Users/yan.boika/Documents/programming/C++/endProject/users.txt");
     string temp;

     for(int i = 1; i <= userCount; i++){
         string name;
         string lastName;
         string address;
         string gender;

         getline(userFile, name, ';');
         getline(userFile, lastName, ';');
         getline(userFile, address, ';');
         getline(userFile, gender);
         if(!name.empty()){
             Client newClient(name, lastName, address, gender);
             clients.push_back(newClient);
         }
     }
     userFile.close();
 }




void ShopApp::addClientToTekstFile(const vector<Client>& clients) {
     ofstream userFile;
     userFile.open("/Users/yan.boika/Documents/programming/C++/endProject/users.txt", std::ios::app); // Открытие файла с флагом ios::app для записи в конец файла

     if (userFile.is_open()) {
         //userFile << endl; // Перевод строки перед записью новых данных
         userFile << clients.back().getName() << ";" << clients.back().getLastName() << ";" << clients.back().getAddress() << ";" << clients.back().getGender() << std::endl;
         userFile.close();
     } else {
         cout << "Nie można otworzyć pliku." << endl;
     }
 }

 void ShopApp::addClientsToBinaryFile(const vector<Client>& clients){
     ofstream binaryFile("/Users/yan.boika/Documents/programming/C++/endProject/users.bin", ios_base::out|ios_base::binary); // Открытие файла в бинарном режиме с флагом ios::app для записи в конец файла

     if (binaryFile.is_open()){
         for (const auto& client : clients){
             binaryFile.write(reinterpret_cast<const char*>(&client), sizeof(Client));
         }
         binaryFile.close();
     }else{
         cout << "Nie można otworzyć pliku." << endl;
     }
 }


void ShopApp::newUserCreator(vector<Client>& clients) {
     string newUserName;
     string newUserLastName;
     string newUserAddress;
     string newUserGender;
     int n = 0;
     char decision;
     while(n != 1){
         cout << "Enter your name: "; cin >> newUserName;
         cout << endl;
         cout << "Enter your Last name "; cin >> newUserLastName;
         cout << endl;
         cout << "Enter your gender (M/F) "; cin >> newUserGender;
         cout << endl;
         cout << "Enter your delivery address ";
         cin.ignore();
         getline(cin, newUserAddress);

         cout << "Do you want to edit user infirmation?(Y/N) "; cin >> decision;
         if(decision == 'N'){
             cout << "User created successfully." << endl;
             n = 1;
         }
         else{
             cout << "Let's edit you information! " << endl;
         }
     }
     Client newClient(newUserName, newUserLastName, newUserAddress, newUserGender);

     clients.push_back(newClient);

     addClientToTekstFile(clients);
     addClientsToBinaryFile(clients);

 }



void ShopApp::loadProductFromFile(std::vector<Product> &products){
     fstream productFile;
     productFile.open("/Users/yan.boika/Documents/programming/C++/endProject/product.txt");

     for(int i = 1; i <= 12; i++){
         string productName;
         string strPrice;
         string strVatRate;
         string strQuantity;

         getline(productFile, productName, ';');
         getline(productFile, strPrice, ';');
         getline(productFile, strVatRate, ';');
         getline(productFile, strQuantity);

         double price = std::stod(strPrice); //преобзоравание string в double, потому что из файла получает строку
         double vatRate = std::stod(strVatRate);
         int quantity = stoi(strQuantity);
         if(!productName.empty()){

             Product newProduct(productName, price, vatRate, quantity);
             products.push_back(newProduct);
         }
     }
     productFile.close();
 }

 void ShopApp::showAvailableProducts(std::vector<Product> &products){
     cout << endl;
     cout << "Here our product list " << endl;
     cout << endl;
     for (const auto& product : products) {
         cout << product.getProductName() << ";" << product.getPrice() << ";" << product.getVatRate() << ";" << product.getQuantity() << endl;
     }
     cout << endl;
 }

 void ShopApp::showUserList(vector<Client>& clients){
     cout << endl;
     for (const auto& client : clients) {
         cout << client.getName() << ";" << client.getLastName() << ";" << client.getAddress() << ";" << client.getGender() << endl;
     }
 }

void saveOrderInfoToTekstFile(Client client, Order order){
     fstream orderFile;
     orderFile.open("/Users/yan.boika/Documents/programming/C++/endProject/order.txt", std::ios::app); // std::ios::app чтобы записать в конец файла

     if(orderFile.is_open()){
         orderFile << "Order of: " << client.getName() << " "<< client.getLastName() << " user " << endl;
         orderFile <<  "Product Name: " << order.getProduct() << endl;
         orderFile << "Product Count: " << order.getCount() << endl;
         orderFile << "VAT Rate: " << order.getVatRate() << endl;
         orderFile << "Price: " << order.getPrice() * order.getCount() << endl;
         orderFile << "Delivery Date: " << order.getOrderDate() << endl;
         orderFile << "Total Value: " << order.getOrderValue() << endl;
         orderFile << "Payment Method: " << order.getPaymentMethod() << endl;

         orderFile << "------------------------" << endl;
         orderFile << endl;
     }
     orderFile.close();
 }

 void ShopApp::createOrder(vector<Client>& clients, std::vector<Product> &products, map<string, Order>& orders) {
     int n = 0;
     char decision;
     string userName;
     string userLastName;
     cout << "Let's create your order! " << endl << endl;
     cout << "Please enter your name to confirm that you are a user: ";
     cin >> userName;
     cout << "Now, please enter your last name: ";
     cin >> userLastName;
     cout << endl;

     for (const auto& client : clients) {
         if (client.getName() == userName && client.getLastName() == userLastName) {
             cout << "OK, let's create your order." << endl;

             // Просмотр доступных продуктов
             showAvailableProducts(products);

             string productName;
             cout << "Enter the product name: ";
             cin.ignore();
             getline(cin, productName);

             bool productFound = false;

             for(const auto& product : products){
                 if(product.getProductName() == productName){
                     productFound = true;

                     while(n != 1){
                         // Найден продукт, запрашиваем количество
                         int productCount;
                         cout << "Enter the product count: ";
                         cin >> productCount;

                         if(productCount <= product.getQuantity()){
                             string paymentMethod;
                             cout << "Enter the way you want to pay (DebitCard, Cash, Crypto): ";
                             cin >> paymentMethod;

                             while (true) {
                                 if (paymentMethod == "DebitCard" || paymentMethod == "Cash" || paymentMethod == "Crypto") {
                                     break;
                                 }else{
                                     cout << "Invalid payment method. Please enter a valid payment method: ";
                                     cin >> paymentMethod;
                                 }
                             }

                             string deliveryDate;
                             cout << "Enter when you want to get your order (DD.MM.YYYY): ";
                             cin.ignore();
                             getline(cin, deliveryDate);

                             double totalValue = (product.getPrice() * (1 + (product.getVatRate())/100)) * productCount;

                             // Создание нового заказа
                             Order newOrder(productName, productCount, product.getVatRate(), product.getPrice(), deliveryDate, totalValue, paymentMethod);

                             // Добавление заказа в список заказов по фамилии, т.к имена могут повторяться
                             orders.insert(pair<string, Order>(userLastName, newOrder));

                             cout << "Maybe you want to edit your order: (Y/N) ";
                             cin >> decision;
                             if(decision == 'N'){
                                 cout << "Order created successfully." << endl;
                                 saveOrderInfoToTekstFile(client, newOrder);
                                 n = 1;
                                 return;
                             }
                         } else {
                             cout << "Not enough quantity available. Please enter a lower quantity." << endl;
                         }
                     }
                 }
             }

             if(!productFound){
                 cout << "Product not found." << endl;
                 return;
             }
         }
     }

     cout << "User not found." << endl;
 }
void ShopApp::showOrderList(vector<Client>& clients, std::vector<Product> &products, map<string, Order>& orders){
     fstream orderFile;
     orderFile.open("/Users/yan.boika/Documents/programming/C++/endProject/order.txt");

     string userName;
     cout << "Please, enter your Name: ";
     cin >> userName;
     string userLastName;
     cout << "Please, enter your Lastname: ";
     cin >> userLastName;
     int userCount = 0;

     for(const auto& client : clients){
         if (client.getName() == userName && client.getLastName() == userLastName){
             userCount++;
         }
     }
     if(userCount == 0){
         cout << "User is not found " << endl;
         return;
     }

     // Выводим информацию о заказах
     cout << endl;
     cout << "Orders information for user " << userName << " " << userLastName << ":" << endl << endl;



     for(const auto& client : clients){
         if (client.getName() == userName && client.getLastName() == userLastName){
             if (orderFile.is_open()){
                 bool foundUser = false;
                 string temp;
                 std::string userIdentifier = "Order of: " + userName + " " + userLastName + " user";
                 while(getline(orderFile, temp)){
                     if (temp.find(userIdentifier) != std::string::npos) { //std::string::npos Она обозначает конечную позицию или недопустимую позицию в строке.
                         foundUser = true;
                         cout << temp << endl;
                         while (std::getline(orderFile, temp)) {
                             if (temp == "------------------------") {
                                 cout << temp << endl << endl;
                                 break;
                             }
                             cout << temp << endl;
                         }
                     }
                 }
                 if (!foundUser) {
                     std::cout << "No orders found for user: " << userName << " " << userLastName << std::endl;
                     return;
                 }
             }
             else{
                 cout << "Failed to open file." << std::endl;
                 return;
             }
         }

     }
     orderFile.close();
 }

void ShopApp::run(){
     int userCount = takeUserCount();
     vector<Client> clients;
     vector<Product> products;
     map<string, Order> orders;
     loadClientFromFile(clients, userCount);
     loadProductFromFile(products);

     int n;
     menu();
    
    while (cout << "What would you like to do: ", cin >> n) {
        switch(n){
            case 1:
                menu();
                break;
            case 2:
                newUserCreator(clients);
                userCount++;
                break;
             case 3:
                 showAvailableProducts(products);
                 break;
             case 4:
                 createOrder(clients, products, orders);
                 break;
            case 5:
                showOrderList(clients, products, orders);
                break;
            case 6:
                showUserList(clients);
                break;
             case 10:
                 cout << "Okay, we are ending our session :)" << endl;
                 return; // Завершить программу
            default:
                cout << "Invalid option. Try again." << endl;
                break;
        }
        cout << endl;
    }
}
