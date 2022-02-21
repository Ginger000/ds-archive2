// your code here
#include <iostream>
#include "Bar.h"
#include "Foo.h"

potd::Bar::Bar(std::string name){
    f_ = new potd::Foo(name);
}

potd::Bar::Bar(const potd::Bar& other){
    std::cout << "Copy Constructor called." << std::endl; 
    std::string name = other.f_->get_name();
    //delete f_;
    f_ = new potd::Foo(name);
    //this->f_ = other.f_;

    // std::cout << "Copy Constructor called." << std::endl; 
    // std::string name = other.f_->get_name();
    // delete f_;
    // f_ = new potd::Foo(name);
    
}

potd::Bar::~Bar(){ 
    // std::cout << "Destructor called for" << f_->get_name() << "@ this memory location" << this << std::endl; 
    std::cout << "Destructor called for" << std::endl; 
    delete f_;
}

potd::Bar& potd::Bar::operator= (const potd::Bar& that) {
    std::cout << "Overloaded assignment called" << std::endl; 
    std::string name = that.f_->get_name();
    delete f_;
    f_ = new potd::Foo(name);
    //this->f_ = that.f_;
    return *this;

    // std::cout << "Overloaded assignment called" << std::endl; 
    // std::string name = that.f_->get_name();
    // delete f_;
    // f_ = new potd::Foo(name);
    // return *this;
    
}

std::string potd::Bar::get_name() {
    return f_->get_name();
}
