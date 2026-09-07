#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// 1. Optimal Approach (Single Pass: O(N) time, O(1) space)
void secondSmallestAndsecondLargest3(const vector<int>& arr) {
    if (arr.size() < 2) {
        cout << -1 << " " << -1 << endl;
        return;
    }

    int small = INT_MAX, second_small = INT_MAX;
    int big = INT_MIN, second_big = INT_MIN;

    for (int num : arr) {
        // Track smallest and second smallest
        if (num < small) {
            second_small = small;
            small = num;
        } else if (num > small && num < second_small) {
            second_small = num;
        }

        // Track largest and second largest
        if (num > big) {
            second_big = big;
            big = num;
        } else if (num < big && num > second_big) {
            second_big = num;
        }
    }

    if (second_small == INT_MAX || second_big == INT_MIN) {
        cout << "No valid second smallest or second largest element (all elements might be equal)." << endl;
    } else {
        cout << "[Optimal] Second Smallest: " << second_small << endl;
        cout << "[Optimal] Second Largest:  " << second_big << endl;
    }
}

// 2. Better Approach (Two Pass: O(2N) time, O(1) space)
void secondSmallestAndsecondLargest2(const vector<int>& arr) {
    if (arr.size() < 2) {
        cout << -1 << " " << -1 << endl;
        return;
    }

    int small = INT_MAX, big = INT_MIN;
    for (int num : arr) {
        small = min(small, num);
        big = max(big, num);
    }

    int second_small = INT_MAX, second_big = INT_MIN;
    for (int num : arr) {
        if (num > small && num < second_small) {
            second_small = num;
        }
        if (num < big && num > second_big) {
            second_big = num;
        }
    }

    if (second_small == INT_MAX || second_big == INT_MIN) {
        cout << "No valid second element." << endl;
    } else {
        cout << "[Better]  Second Smallest: " << second_small << endl;
        cout << "[Better]  Second Largest:  " << second_big << endl;
    }
}

// 3. Brute Force Approach (Sorting: O(N log N) time, handles duplicates)
void secondSmallestAndsecondLargest(vector<int> arr) {
    if (arr.size() < 2) {
        cout << -1 << " " << -1 << endl;
        return;
    }

    sort(arr.begin(), arr.end());

    int n = arr.size();
    int second_small = -1, second_big = -1;

    // Find second smallest (first element strictly greater than arr[0])
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[0]) {
            second_small = arr[i];
            break;
        }
    }

    // Find second largest (first element strictly smaller than arr[n-1])
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] != arr[n - 1]) {
            second_big = arr[i];
            break;
        }
    }

    cout << "[Brute]   Second Smallest: " << second_small << endl;
    cout << "[Brute]   Second Largest:  " << second_big << endl;
}

int main() {
    vector<int> arr = {5, 10, 4, 11, 9, 2, 6};
    
    secondSmallestAndsecondLargest(arr);
    secondSmallestAndsecondLargest2(arr);
    secondSmallestAndsecondLargest3(arr);

    return 0;
}