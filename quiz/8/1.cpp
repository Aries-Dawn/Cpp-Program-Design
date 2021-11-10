#include <iostream>
using namespace std;

class    Hello  
   
   {  
   
       static       int    value;  
   
       int    num;  
   
       public:  
   
       int    sum(    int    i,    int    j) {    return    i + j; }  
   
   };  
   
   
   int    main()  
   
   {  
   
    cout    <<       sizeof   (Hello)    <<    endl;   
   
    return 0;  
   
   }  