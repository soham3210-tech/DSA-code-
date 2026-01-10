#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];

        if (mp.find(complement) != mp.end())
        {
            return {mp[complement], i};
        }

        mp[nums[i]] = i;
    }

    return {};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);
    cout << result[0] << " " << result[1];

    return 0;
}
