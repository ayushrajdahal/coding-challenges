// Is Anagram

// Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.

// An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

// Example 1:

// Input: s = "racecar", t = "carrace"

// Output: true
// Example 2:

// Input: s = "jar", t = "jam"

// Output: false
// Constraints:

// s and t consist of lowercase English letters.

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        };

        map<char, int> count_s;
        map<char, int> count_t;

        for (int i = 0; i < s.length(); i++)
        {
            count_s[s[i]] += 1;
            count_t[t[i]] += 1;
        }

        return count_s == count_t;
    }
};
