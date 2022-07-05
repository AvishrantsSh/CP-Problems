#include<iostream>
#include<vector>

using namespace std;

void primeSieve(int num){
    vector<bool> arr(num, 0);
    for(int i = 2; i <= num; i++){
        if(arr[i]) continue;
        cout << i << " ";
        for(int j = i*i; j<=num; j += i){
            arr[j] = 1;
        }
    }
    cout << endl;
}

void primeFactorize(int num){
    vector<int> arr(num, 0);

    for(int i = 2; i <= num; i++){
        if(arr[i] != 0) continue;
        arr[i] = i;
        for(int j = i*i; j <= num; j+=i){
            if(arr[j] == 0) arr[j] = i;
        }
    }

    while(num != 1){
        cout << arr[num] << " ";
        num = num / arr[num];
    }

    cout << endl;
}

int main(){
    primeSieve(50);
    primeFactorize(11136);
    return 0;
}