#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Client.hpp"
#include "ShopApp.hpp"


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

void ShopApp::run(){
    int userCount = takeUserCount();
    vector<Client> clients;

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
            case 10:
                cout << "Okay, we are ending our session :)" << endl;
                return; // End program
            default:
                cout << "Invalid option. Try again." << endl;
                break;
        }
        cout << endl;
    }
}
