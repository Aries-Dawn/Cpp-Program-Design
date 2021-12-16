#include <iostream>

using namespace std;
  class     Animal{  
   
        private:  
   
        int     weight;  
   
        public:  
   
    Animal(    int     w =     0    ){weight = w;}  
   
        void     print(){cout     <<     weight     <<     endl;}  
   
   };  
   
   
   class     Dog:     public     Animal{  
   
        public:  
   
    Dog(    int     w =     0    ):Animal(w){}  
   
        void     print(){ cout     <<         "Dog "    ; Animal::print();}  
   
        virtual    void     speak(){ cout     <<         "wangwang"    <<     endl;}  
   
   };  
   
   
   int     main()  
   
   {  
   
    Dog dog(    5    );  
   
    Animal * p = &dog;  
   
    p->speak();  
   
        return         0    ;  
   
   }  