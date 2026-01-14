#include <iostream>
#include <vector>
#include <algorithm> // for max()

using namespace std;

int maxNonAdjacentSum(const vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return arr[0];

    int prev2 = arr[0];              // dp[i-2]
    int prev1 = max(arr[0], arr[1]); // dp[i-1]

    for (int i = 2; i < n; i++)
    {
        int curr = max(prev1, arr[i] + prev2); // dp[i] = max(dp[i-1], arr[i] + dp[i-2])
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    vector<int> arr = {3, 2, 5, 10, 7};
    cout << "Maximum sum of non-adjacent elements: " << maxNonAdjacentSum(arr) << endl;
    return 0;
}
