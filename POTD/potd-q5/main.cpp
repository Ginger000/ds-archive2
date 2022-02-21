// your code here
#include <iostream>
#include "Food.h"
#include "q5.h"
using namespace std;

int main() {
    Food apple;
    cout << apple.get_quantity() <<endl;
    increase_quantity(&apple);
    cout << apple.get_quantity() <<endl;
}