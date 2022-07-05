#include <iostream>

using namespace std;

int divisible(int num, int a, int b){
    return num / a + num / b - num / (a * b);
}

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    cout << divisible(1000, 5, 7) << endl;
    cout << gcd(10, 20) << endl;
}