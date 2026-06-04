#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        int need = target - nums[i];

        if (mp.find(need) != mp.end())
        {
            return {mp[need], i};
        }

        mp[nums[i]] = i;
    }

    return {}; // will never reach here as solution exists
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = twoSum(nums, target);
    cout << ans[0] << " " << ans[1];
}
