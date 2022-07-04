#include <iostream>
#include <vector>

using namespace std;

bool checkPowerOfTwo(int num){
    return num & (num - 1);
}

int countOnes(int num){
    int count;
    for(count = 0; num > 0; count++)
        num = num & (num - 1);
    
    return count;
}

void subsets(vector<int> &arr){
    int n = arr.size();
    for(int i = 0; i < (1<<n); i++){
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}

int main(){
    cout << checkPowerOfTwo(5) << endl;
    cout << countOnes(5) << endl;
    vector<int> arr = {1, 2, 3, 4, 5};
    subsets(arr);
    return 0;
}