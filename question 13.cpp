#include <iostream>
#include <vector>

using namespace std;

int findDuplicate(const vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];

    // Phase 1: Detect cycle
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Phase 2: Find entry point of cycle
    slow = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main()
{
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << findDuplicate(nums) << endl;
    return 0;
}
