#include <iostream>
#include <vector>

using namespace std;

int findSoloElement(vector<int> &arr){
    int ans = 0;
    for(int i = 0; i < arr.size(); i++)
        ans ^= arr[i];
    
    return ans;
}

int main(){
    vector<int> arr = {2, 3, 4, 3, 4, 5, 5};
    cout << findSoloElement(arr);
    return 0;
}