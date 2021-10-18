g++ -shared -fPIC -o libswap.so swap.cpp
g++ -o main.out -L. main.cpp -lswap
./main.out