// Animal.h
#include <iostream>

class Animal{
    private:
        std::string type_;
    protected:
        std::string food_;
    public:
        std::string getType();
        void setType(std::string type);
        std::string getFood();
        void setFood(std::string food);
        virtual std::string print();
        Animal();
        Animal(std::string type, std::string food);
};