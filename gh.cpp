#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countSubarraysWithSumK(const vector<int> &arr, int K)
{
    unordered_map<long long, int> mp;
    long long sum = 0;
    int count = 0;

    mp[0] = 1; // Important base case

    for (int x : arr)
    {
        sum += x;

        if (mp.find(sum - K) != mp.end())
        {
            count += mp[sum - K];
        }

        mp[sum]++;
    }

    return count;
}

int main()
{
    vector<int> arr = {1, 1, 1};
    int K = 2;

    cout << countSubarraysWithSumK(arr, K) << endl;
    return 0;
}
