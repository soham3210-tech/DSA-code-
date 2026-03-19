#include <iostream>
#include <vector>
using namespace std;

int maxSumSubarray(vector<int> &arr, int k)
{
    int n = arr.size();
    if (n < k)
        return -1; // Not enough elements

    int maxSum = 0;
    int windowSum = 0;

    // Sum of first k elements
    for (int i = 0; i < k; i++)
    {
        windowSum += arr[i];
    }
    maxSum = windowSum;

    // Slide the window
    for (int i = k; i < n; i++)
    {
        windowSum += arr[i] - arr[i - k]; // Add next element, remove first element of window
        if (windowSum > maxSum)
        {
            maxSum = windowSum;
        }
    }

    return maxSum;
}

int main()
{
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;

    cout << "Maximum sum of subarray of size " << k << " is "
         << maxSumSubarray(arr, k) << endl;

    return 0;
}