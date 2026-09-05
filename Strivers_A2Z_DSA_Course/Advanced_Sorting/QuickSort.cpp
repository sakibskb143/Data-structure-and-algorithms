#include <iostream>
#include <vector>
using namespace std;

int partitionIndex(vector<int>& arr, int low, int high)
{
    int pivot = arr[low];

    int i = low;
    int j = high;

    while (i < j)
    {
        // Find element greater than pivot
        while (arr[i] <= pivot && i <= high)
        {
            i++;
        }

        // Find element smaller than or equal to pivot
        while (arr[j] > pivot && j >= low)
        {
            j--;
        }

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }

    // Put pivot in its correct position
    swap(arr[low], arr[j]);

    return j;
}

void QuickSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int partition_index = partitionIndex(arr, low, high);

        QuickSort(arr, low, partition_index - 1);
        QuickSort(arr, partition_index + 1, high);
    }
}

int main()
{
    vector<int> arr = {5, 2, 7, 3, 8, 1, 6};

    int n = arr.size();

    cout << "Before sorting: " << endl;

    for (int x : arr)
    {
        cout << x << " ";
    }

    cout << endl;

    QuickSort(arr, 0, n - 1);

    cout << "After sorting: " << endl;

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}