#include <iostream>

using namespace std;


void myValueFunc(int myInt){
    myInt += 1;
    cout<<"Function Value: "<< myInt<<endl;
}

void myRefFunc(int& x){
    x += 1;
    cout<<"Function Reference: "<< x<<endl;
}

void myBothFunc(int& x, int y){
    x = x*y;
    y = x;
    cout<<"x: "<< x << " y: " << y <<endl;

}

int main(){
    cout<<"Reference and Value"<<endl;

    int myInt = 3;
    int myInt2 = 3;
    //myValueFunc(myInt);
    myBothFunc(myInt, myInt2);

    cout<<"Main int 1: "<<myInt<<endl;
    cout<<"Main int 2: "<<myInt2<<endl;


    return 0;
}
