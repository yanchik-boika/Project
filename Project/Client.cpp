#include "Client.hpp"


#include <iostream>

 using namespace std;

 Client::Client() {}

 Client::Client(const std::string& name, const std::string& lastName,
                const std::string& address, const std::string& gender)
     : name(name), lastName(lastName), address(address), gender(gender) {}

 std::string Client::getName() const {      // 4 functions to get variable values
     return name;
 }

 std::string Client::getLastName() const {
     return lastName;
 }

 std::string Client::getAddress() const {
     return address;
 }

 std::string Client::getGender() const {
     return gender;
 }
