// Pet.cpp

#include "Pet.h"

void Pet::setType(std::string nu_type) {
    this->Animal::setType(nu_type);
}

void Pet::setName(string name){
    name_ = name;
}

void Pet::setOwnerName(string owner_name){
    owner_name_ = owner_name;
}
    
std::string Pet::getType() {
    return this->Animal::getType();
}

string Pet::getName(){
    return name_;
}
string Pet::getOwnerName(){
    return owner_name_;
}

string Pet::print() {
    return "My name is " + name_;
}

Pet::Pet() : Animal::Animal() { 
    name_ = "Fluffy";
    owner_name_ = "Cinda";
}

// Pet::Pet(string type, string food, string name, string owner_name): Animal(string type, std::string food){
//     name_ = name;
//     owner_name_ = owner_name;
// }

Pet::Pet(string type, string food, string name, string owner_name) {
    this->setType(type);
    food_ = food;
    name_ = name;
    owner_name_ = owner_name;
}
