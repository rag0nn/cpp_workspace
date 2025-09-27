#include <iostream>
using namespace std;

int main(){
    int x = 10;
    
    try {

        if (x == 10){
            throw(x);
        }
    }
    catch(int a){
        cout << "num: " <<a <<endl ;
    }


    return 0;
}