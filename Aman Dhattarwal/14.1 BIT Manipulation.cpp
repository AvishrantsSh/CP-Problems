#include <iostream>

using namespace std;

int getBit(int num, int pos){
    return num >> pos & 1;
}

int setBit(int num, int pos){
    return num | (1 << pos);
}

int clearBit(int num, int pos){
    return num & ~(1 << pos);
}

int updateBit(int num, int pos, int v){
    return (num & ~(1 << pos)) | (v << pos);
}

int main(){
    cout << getBit(5, 1);
    cout << setBit(5, 1);
    cout << clearBit(5, 2);
    cout << updateBit(5, 1, 1);
    return 0;
}