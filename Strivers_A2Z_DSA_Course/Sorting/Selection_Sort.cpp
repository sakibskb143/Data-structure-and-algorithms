#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr = {13, 46, 24, 52, 20, 9};

    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        swap(arr[i], arr[min_index]);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // time complexity : big O(n^2);
    // space complexity : big O(1)

    return 0;
}