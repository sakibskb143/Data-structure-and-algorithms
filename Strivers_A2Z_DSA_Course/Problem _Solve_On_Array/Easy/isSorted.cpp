#include <bits/stdc++.h>
using namespace std;

void isSortedArray(vector<int>& arr) {
    int n = arr.size();

    if (n <= 1) {
        cout << "True" << endl;
        return;
    }

    bool isSorted = true;

    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            isSorted = false;
            break;
        }
    }

    isSorted ? cout << "True" << endl : cout << "False" << endl;
}

int main() {

    vector<int> arr = {3, 6, 3, 7, 4, 7};

    isSortedArray(arr);

    return 0;
}