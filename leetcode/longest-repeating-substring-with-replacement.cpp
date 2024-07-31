// Longest Repeating Substring With Replacement

// You are given a string s consisting of only uppercase english characters and an integer k. You can choose up to k characters of the string and replace them with any other uppercase English character.

// After performing at most k replacements, return the length of the longest substring which contains only one distinct character.

// Example 1:

// Input: s = "XYYX", k = 2

// Output: 4
// Explanation: Either replace the 'X's with 'Y's, or replace the 'Y's with 'X's.

// Example 2:

// Input: s = "AAABABB", k = 1

// Output: 5
// Constraints:

// 1 <= s.length <= 1000
// 0 <= k <= s.length

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        // initialize charcount with 26 elements, each with value zero
        vector<int> charcount(26, 0);

        // left boundary of the sliding window
        int left = 0;

        // this stores the highest frequency of any character within the window
        int highest_freq = 0;

        for (int right = 0; right < s.length(); right++)
        {
            charcount[s[right] - 'A']++;
            highest_freq = max(highest_freq, charcount[s[right] - 'A']);

            // shift the left pointer until the non-highest chars have frequency more than k
            if (right - left + 1 - highest_freq > k)
            {
                charcount[s[left] - 'A']--;
                left++;
            }
        }

        // since last right pointer is the length itself, this returns the size of the window.
        return s.length() - left;
    }
};
