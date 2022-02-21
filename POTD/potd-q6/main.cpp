// Your code here! :)
#include <iostream>
#include "student.h"
#include "q6.h"

int main() {
    using namespace potd;
    Student sally;
    Student& refSally = sally;
    std::cout << sally.get_grade() << std::endl;
    std::graduate(refSally);
    std::cout << sally.get_grade() << std::endl;

}