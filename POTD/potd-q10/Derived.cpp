#include "Derived.h"
//#include "Base.h"

std::string Derived::foo() {
        return "I will not eat them.";
    }

std::string Derived::bar() {
    return "And Ham";
}

Derived::~Derived(){}