#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestSubarrayWithSumK(const vector<int>& arr, int K) {
    unordered_map<long long, int> mp;
    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        if (sum == K) {
            maxLen = i + 1;
        }

        if (mp.find(sum - K) != mp.end()) {
            maxLen = max(maxLen, i - mp[sum - K]);
        }

        if (mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }

    return maxLen;
}

int main() {
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int K = 15;

    cout << longestSubarrayWithSumK(arr, K) << endl;
    return 0;
}
