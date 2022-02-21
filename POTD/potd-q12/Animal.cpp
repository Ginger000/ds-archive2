// Animal.cpp
#include "Animal.h"
#include <string>

std::string Animal::getType(){ return type_; }
void Animal::setType(std::string type){type_ = type;}
std::string Animal::getFood(){ return food_;}
void Animal::setFood(std::string food){food_ = food;}

std::string Animal::print(){
    std::string type = this->getType();
    return "I am a " + type;
}

Animal::Animal(){
            type_ = "cat";
            food_ = "fish";
        };
Animal::Animal(std::string type, std::string food){
    type_ = type;
    food_ = food;
}
