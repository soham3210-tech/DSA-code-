#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    vector<int> freq(256, 0);

    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < s.length(); right++)
    {
        freq[s[right]]++;

        // If duplicate found, shrink window
        while (freq[s[right]] > 1)
        {
            freq[s[left]]--;
            left++;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main()
{
    string s = "abcabcbb";
    cout << "Longest Substring Length: "
         << lengthOfLongestSubstring(s) << endl;

    return 0;
}
