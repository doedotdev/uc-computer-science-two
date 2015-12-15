// 24 to 26 bits

#include <iostream>

using namespace std;

int main(){

    string bits;
    for(int i = 0; i < 12; i++){
        bits+= "01";
    }
    cout<<bits.length()<<endl;
    cout<<bits<<endl;
    int first = 0;
    int last = 0;
    for(int i = 0; i < 24; i++){
        char c = bits[i];
        if(i < 12){
            first += c - '0';
        }
        else{
            last += c - '0';
        }
    }
    cout<<first<<" :: "<< last<< endl;


return 0;
}
