// your code here
#include "Food.h"
#include "q5.h"
void increase_quantity(Food* f){
    int quant = (*f).get_quantity();
    quant++;
    (*f).set_quantity(quant);
}