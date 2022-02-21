// Pet.h
#include "Animal.h"
using namespace std;


class Pet : public Animal
{
private:
    string name_;
    string owner_name_;
public:
    Pet();
    Pet(string type, string food, string name, string owner_name);
    // Pet(string type, string food, string name, string owner_name): Animal(string type, std::string food);
    void setType(string nu_type);
    void setName(string name);
    void setOwnerName(string owner_name);
    
    string getType();
    string getName();
    string getOwnerName();

    string print();
};


