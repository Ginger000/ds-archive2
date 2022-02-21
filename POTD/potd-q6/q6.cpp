// Your code here! :)
#include "student.h"
#include "q6.h"
void std::graduate(potd::Student& student){
    int grade = student.get_grade();
    grade++;
    student.set_grade(grade);
}