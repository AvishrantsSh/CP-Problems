#include <iostream>

using namespace std;

int sum(int n){
    if (n == 0) return 0;
    return n + sum(n-1);
}

int power(int n, int pow){
    if(pow == 0) return 1;
    return n * power(n, pow-1);
}

int factorial(int n){
    if(n == 0) return 1;
    return n * factorial(n-1);
}

int nth_fibonacci(int n){
    if(n == 0 || n == 1) return n;
    return nth_fibonacci(n-1) + nth_fibonacci(n-2);
}

int main(){
    cout << sum(10) << endl;
    cout << power(2, 3) << endl;
    cout << factorial(5) << endl;
    cout << nth_fibonacci(4) << endl;
}

