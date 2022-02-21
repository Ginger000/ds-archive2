// Your code here! :)
#include "student.h"

potd::Student::Student(){
    name_ = "Sally";
    grade_ = 5;
}

string potd::Student::get_name() {
    return name_;
}
void potd::Student::set_name(string name){
    name_ = name;
}

int potd::Student::get_grade() {
    return grade_;
}

void potd::Student::set_grade(int grade){
    grade_ = grade;
}