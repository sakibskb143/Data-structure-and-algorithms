#include <bits/stdc++.h>
using namespace std;

void Merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;

    int left = low;
    int right = mid + 1;

    // Compare both halves
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Remaining elements of left half
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Remaining elements of right half
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy sorted elements back to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void MergeSort(vector<int>& arr, int low, int high) {

    if (low >= high)
        return;

    int mid = low + (high - low) / 2;

    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);

    Merge(arr, low, mid, high);
}

int main() {

    vector<int> arr = {3, 2, 2, 4, 1, 5, 2, 6, 4};

    int n = arr.size();

    MergeSort(arr, 0, n - 1);

    // Print sorted array
    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}