g++ -shared -fPIC -o libfunction.so function.cpp
g++ -o main.out -L. main.cpp -lfunction
./main.out