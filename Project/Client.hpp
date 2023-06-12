#ifndef Client_hpp
#define Client_hpp

#include <string>

 class Client {
 private:
     std::string name;
     std::string lastName;
     std::string address;
     std::string gender;

 public:
     Client();
     Client(const std::string& name, const std::string& lastName, const std::string& address, const std::string& gender);

     std::string getName() const;
     std::string getLastName() const;
     std::string getAddress() const;
     std::string getGender() const;
 };


#endif /* Client_hpp */
