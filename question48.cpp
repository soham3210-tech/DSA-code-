#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = 5;

    selectionSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubarrayWithSumK(vector<int> &arr, int K)
{
    unordered_map<long long, int> prefixMap;

    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        // Case 1: if sum itself is K
        if (sum == K)
        {
            maxLen = i + 1;
        }

        // Case 2: if (sum - K) seen before
        if (prefixMap.find(sum - K) != prefixMap.end())
        {
            int len = i - prefixMap[sum - K];
            if (len > maxLen)
            {
                maxLen = len;
            }
        }

        // Store first occurrence of prefix sum
        if (prefixMap.find(sum) == prefixMap.end())
        {
            prefixMap[sum] = i;
        }
    }

    return maxLen;
}

int main()
{
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int K = 15;

    cout << "Length: " << longestSubarrayWithSumK(arr, K) << endl;

    return 0;
}