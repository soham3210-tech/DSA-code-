#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mp; // value -> index

    for (int i = 0; i < nums.size(); i++)
    {
        int needed = target - nums[i];

        // Check if needed number already exists
        if (mp.find(needed) != mp.end())
        {
            return {mp[needed], i};
        }

        // Store current number with its index
        mp[nums[i]] = i;
    }

    return {}; // problem guarantees one solution
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    cout << "Indices: " << result[0] << " " << result[1] << endl;

    return 0;
}
