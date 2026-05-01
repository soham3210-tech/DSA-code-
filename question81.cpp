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