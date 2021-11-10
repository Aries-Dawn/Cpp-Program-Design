#include <iostream>
using namespace std;

class     Hello  
   
   {  
   
        static         int     value;  
   
        int     num;  
   
        public:  
   
        int     sum(     int     i,     int     j) {     return     i + j; }  
   
        void     setValue(    int     v) { value = v;}  
   
        int     getValue() {    return     value;}  
   
   };  
   
   
   int     main()  
   
   {  
   
    Hello h1, h2;  
   
    h1.setValue(    5    );  
   
    cout     <<     h2.getValue()     <<     endl;  
   
        return         0    ;  
   
   }  