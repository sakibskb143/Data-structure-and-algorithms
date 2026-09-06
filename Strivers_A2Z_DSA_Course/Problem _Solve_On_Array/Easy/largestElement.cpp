// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>

using namespace std;


int largestElement (vector<int>&arr,int n ){
    int  max_value = arr[0];
    for(int i = 1 ; i < n  ;i++){
        if(arr[i] > max_value){
            max_value = arr[i];
        }
    }
    return max_value;
    
}

int bruteForceApproach (vector<int>&arr){
    sort(arr.rbegin(), arr.rend());
    return arr[0] ;
}

int main() {
   vector<int>arr= {5,10,4,11,9,5,6};
   int max_value = largestElement(arr,arr.size());
   cout <<"Largest Element (optimize) of given array is : " << max_value << endl ;
   max_value = bruteForceApproach(arr);
   cout <<"Largest Element (bruteforce) of given array is : " << max_value << endl ;
    
   
   return 0;
}