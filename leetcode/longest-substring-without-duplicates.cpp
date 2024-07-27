// Longest Substring Without Duplicates

// Given a string s, find the length of the longest substring without duplicate characters.

// A substring is a contiguous sequence of characters within a string.

// Example 1:

// Input: s = "zxyzxyz"

// Output: 3
// Explanation: The string "xyz" is the longest without duplicate characters.

// Example 2:

// Input: s = "xxxx"

// Output: 1
// Constraints:

// 0 <= s.length <= 1000
// s may consist of printable ASCII characters.

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // `substring` contains the unique part of the string being considered
        unordered_set<char> substring;
        int left = 0;
        int max_length = 0;
        for (int right = 0; right < s.length(); right++)
        {
            // remove characters from the left index until the character at the right becomes unique in the substring
            while (substring.find(s[right]) != substring.end())
            {
                substring.erase(s[left]);
                left++;
            }
            substring.insert(s[right]);
            // length of the current substring being considered; alternatively, we could have done right - left + 1
            int current_length = substring.size();

            // since the current length can change to a shorter-than-max value as soon as the right value being considered is already in the substring
            max_length = max(max_length, current_length);
        }
        return max_length;
    }
};
