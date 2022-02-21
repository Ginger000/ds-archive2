#include <iostream>
#include "Base.h"
//#include <string>

class Derived : public Base
{

public:
    std::string foo();
    std::string bar();
    virtual ~Derived();
};