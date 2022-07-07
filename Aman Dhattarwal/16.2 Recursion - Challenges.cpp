#include <iostream>

using namespace std;

bool is_sorted(int arr[], int n){
    if(n == 1) return true;
    return arr[0] < arr[1] && is_sorted(arr + 1, n - 1);
}

void decreasingOrder(int n){
    if(n == 0) return;
    cout << n << endl;
    decreasingOrder(n-1);
}

void increasingOrder(int n){
    if(n == 0) return;
    increasingOrder(n-1);
    cout << n << endl;
}

int first_occurence(int arr[], int n, int index, int val){
    if(index == n) return -1;
    if (arr[index] == val) return index;
    return first_occurence(arr, n, index + 1, val);
}

int last_occurence(int arr[], int n, int index, int val){
    if(index == n) return -1;
    int tmp = last_occurence(arr, n, index + 1, val);
    if(tmp != -1) return tmp;
    if(arr[index] == val) return index;
    return -1;
}

int main(){
    int arr[] = {1, 2, 3, 6, 5};
    cout << is_sorted(arr, 5) << endl;
    decreasingOrder(5);
    cout << endl;
    increasingOrder(5);
    cout << endl;
    cout << first_occurence(arr, 5, 0, 6) << endl;
    cout << endl;
    cout << last_occurence(arr, 5, 0, 6) << endl;
}