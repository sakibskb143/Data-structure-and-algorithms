#include <bits/stdc++.h>
using namespace std;

void leftRotateByOne(vector<int>& arr)
{
    int n = arr.size();

    if (n <= 1)
        return;

    for (int i = 1; i < n; i++)
    {
        swap(arr[i - 1], arr[i]);
    }
}

int main()
{
    vector<int> arr = {5, 2, 8, 1, 9};

    leftRotateByOne(arr);

    for (int x : arr)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}