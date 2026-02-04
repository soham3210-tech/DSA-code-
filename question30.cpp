#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    string s = "aabbcdd";
    unordered_map<char, int> freq;

    for (char c : s)
        freq[c]++;

    for (char c : s)
    {
        if (freq[c] == 1)
        {
            cout << c;
            return 0;
        }
    }

    cout << "No non-repeating character";
    return 0;
}
