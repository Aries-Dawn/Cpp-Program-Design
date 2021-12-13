#include <iostream>
using namespace std;

void displaySquare(int side=4, char filledCharacter='*');

int main(){
    displaySquare();
    cout<<"-------------"<<endl;
    displaySquare(6,'#');
}


void displaySquare(int side, char filledCharacter){
    for(int i = 0;i < side;i++){
        for (int j = 0; j < side; j++)
        { 
            cout<<filledCharacter;
        }
        cout<<endl;
    }
}