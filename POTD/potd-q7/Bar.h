// your code here
#include "Foo.h"

namespace potd{
    class Bar {
        private:
            potd::Foo* f_;
        public:
            Bar(std::string name);
            
            Bar(const potd::Bar&);
            ~Bar();
            Bar& operator= (const Bar&);
            std::string get_name();
        };
};


