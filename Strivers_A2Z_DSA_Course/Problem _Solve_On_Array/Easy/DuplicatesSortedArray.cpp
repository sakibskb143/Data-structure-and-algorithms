#include <bits/stdc++.h>
using namespace std;


// =====================================================
// Approach 1: Two Pointer
// Time: O(n) after sorting
// Extra Space: O(1)
// =====================================================

int removeDuplicatesTwoPointer(vector<int>& arr) {

    int n = arr.size();

    if (n == 0)
        return 0;

    int i = 0;

    for (int j = 1; j < n; j++) {

        if (arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }

    return i + 1;
}


// =====================================================
// Approach 2: Set
// Time: O(n log n)
// Extra Space: O(n)
// =====================================================

int removeDuplicatesSet(vector<int>& arr) {

    set<int> st;

    for (int x : arr) {
        st.insert(x);
    }

    int k = 0;

    for (int x : st) {
        arr[k] = x;
        k++;
    }

    return k;
}


int main() {

    vector<int> arr = {5, 5, 6, 2, 6, 3, 6, 5};

    // Original array is unsorted
    cout << "Original Array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;


    // Sort first because this is a sorted-array problem
    sort(arr.begin(), arr.end());

    cout << "Sorted Array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;


    // -------------------------
    // Approach 1
    // -------------------------

    int k1 = removeDuplicatesTwoPointer(arr);

    cout << "\nTwo Pointer Approach:" << endl;
    cout << "Unique elements: " << k1 << endl;

    cout << "Array: ";
    for (int i = 0; i < k1; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    // -------------------------
    // Approach 2
    // -------------------------

    // Create another array because
    // the first approach modified arr
    vector<int> arr2 = {5, 5, 6, 2, 6, 3, 6, 5};

    sort(arr2.begin(), arr2.end());

    int k2 = removeDuplicatesSet(arr2);

    cout << "\nSet Approach:" << endl;
    cout << "Unique elements: " << k2 << endl;

    cout << "Array: ";
    for (int i = 0; i < k2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;


    return 0;
}