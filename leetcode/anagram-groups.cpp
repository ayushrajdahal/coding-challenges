// Anagram Groups

// Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order.

// An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

// Example 1:

// Input: strs = ["act","pots","tops","cat","stop","hat"]

// Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]
// Example 2:

// Input: strs = ["x"]

// Output: [["x"]]
// Example 3:

// Input: strs = [""]

// Output: [[""]]
// Constraints:

// 1 <= strs.length <= 1000.
// 0 <= strs[i].length <= 100
// strs[i] is made up of lowercase English letters.

class Solution
{

public:
    // MODIFIED: Use map instead of unordered_map to make it hashable, and use const string& instead of just string to avoid copying
    map<char, int> getCounter(const string &s)
    {
        map<char, int> charCount;

        for (char c : s)
        {
            charCount[c]++;
        }
        return charCount;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // MODIFIED: Changed unordered_map key type to map<char, int>
        // unordered_map requires a hash function for its keys, but std::map<char, int> does not have a default hash function. Switching to map resolves this issue because map uses the `operator<` for ordering.
        map<map<char, int>, vector<string>> anagram_map;

        // MODIFIED: Use const string& to avoid copying
        for (const string &s : strs)
        {
            map<char, int> s_counter = getCounter(s);
            // MODIFIED: Use push_back to add string to the vector
            anagram_map[s_counter].push_back(s);
        }

        // MODIFIED: Corrected the type of res to vector<vector<string>>
        vector<vector<string>> res;

        // MODIFIED: Correctly iterate through the unordered_map to populate res
        for (const auto &pair : anagram_map)
        {
            res.push_back(pair.second);
        }

        return res;
    }
};