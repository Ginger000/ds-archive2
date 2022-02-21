// Your code here! :)
#include <string>
using std::string;
namespace potd{
    class Student {
        private:
            string name_;
            int grade_;
        public:
            string get_name();
            void set_name(string name);
            int get_grade();
            void set_grade(int grade);
            
        Student();
    };
}

