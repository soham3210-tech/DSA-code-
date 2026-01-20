#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubarrayWithSumK(const vector<int> &arr, int k)
{
    unordered_map<long long, int> prefixIndex;
    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        // Case 1: subarray from 0 to i
        if (sum == k)
        {
            maxLen = i + 1;
        }

        // Case 2: subarray exists ending at i
        if (prefixIndex.find(sum - k) != prefixIndex.end())
        {
            maxLen = max(maxLen, i - prefixIndex[sum - k]);
        }

        // Store first occurrence only
        if (prefixIndex.find(sum) == prefixIndex.end())
        {
            prefixIndex[sum] = i;
        }
    }

    return maxLen;
}

int main()
{
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int k = 15;

    cout << longestSubarrayWithSumK(arr, k);
    return 0;
}
