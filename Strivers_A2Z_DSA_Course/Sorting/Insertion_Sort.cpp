#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>arr,int n){
       for(int i  = 0 ; i < n ; i++){
        int j = i ;
          while(j > 0 && arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
          }
    }
    
       for(int i = 0 ; i < n ; i++) {
        cout << arr[i] << " " ;
    }
}

int main() {
    vector<int> arr = {4, 2, 7, 9, 5, 8};
    int n = arr.size();
    insertionSort(arr,n);
    return 0;
}