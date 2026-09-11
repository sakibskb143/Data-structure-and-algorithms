#include <bits/stdc++.h>
using namespace std;

void rotateByLeftSide(vector<int>& arr, int k)
{
    int n = arr.size();

    vector<int> temp(n);

    for (int i = 0; i < n; i++)
    {
        temp[(i - k + n) % n] = arr[i];
    }

    arr = temp;
}

void rotateByRightSide(vector<int>& arr, int k)
{
    int n = arr.size();

    vector<int> temp(n);

    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = arr[i];
    }

    arr = temp;
}

void rotateByK(vector<int>& arr, int k, string side)
{
    int n = arr.size();

    if (n <= 1)
        return;

    k = k % n;

    if (side == "right")
    {
        rotateByRightSide(arr, k);
    }
    else
    {
        rotateByLeftSide(arr, k);
    }
}

int main()
{
    vector<int> arr = {5, 2, 8, 1, 9};

    int k = 2;

    rotateByK(arr, k, "left");

    for (int x : arr)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}