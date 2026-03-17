#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

char firstNonRepeating(string s)
{
    unordered_map<char, int> freq;

    // Step 1: Count frequency
    for (char ch : s)
    {
        freq[ch]++;
    }

    // Step 2: Find first non-repeating
    for (char ch : s)
    {
        if (freq[ch] == 1)
        {
            return ch;
        }
    }

    return '#'; // if no such character
}

int main()
{
    string s;
    cout << "Enter string: ";
    cin >> s;

    char result = firstNonRepeating(s);

    if (result == '#')
        cout << "No non-repeating character\n";
    else
        cout << "First non-repeating character: " << result << endl;

    return 0;
}