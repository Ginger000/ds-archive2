/* Your code here! */
#include <iostream>
#include <string>
using namespace std;

string age = "3";
string myName = "Killua";

string hello() {
    string str1;
    str1 = "Hello world! My name is " + myName + " and I am " + age + " years old.";
    cout << str1 << endl;
    return str1;
}
