#include "epoch.h"
#include <string>
using namespace std;
/* Your code here! */

double hourT;
double dayT;
double yearT;

int hours(time_t x){
    hourT = x / (60 * 60);
    return hourT;
}
int days(time_t x){
    dayT = x / (60 * 60 * 24);
    return dayT;
}
int years(time_t x){
    yearT = x / (60 * 60 * 24 *365);
    return yearT;
}