
#include <iostream>
#include <vector>
using namespace std;

void Bubble_Sort(vector<int>& arr, int n)
{
    // Base case
    if (n == 1)
        return;

    // One complete pass
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    // Recursive call
    Bubble_Sort(arr, n - 1);
}

int main()
{
    vector<int> arr = {3, 5, 6, 2, 1};
    int n = arr.size();

    cout << "Before sorting: ";
    for (int x : arr)
    {
        cout << x << " ";
    }

    Bubble_Sort(arr, n);

    cout << "\nAfter sorting: ";
    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}
