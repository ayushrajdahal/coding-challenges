// Is Palindrome

// Given a string s, return true if it is a palindrome, otherwise return false.

// A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters.

// Example 1:

// Input: s = "Was it a car or a cat I saw?"

// Output: true
// Explanation: After considering only alphanumerical characters we have "wasitacaroracatisaw", which is a palindrome.

// Example 2:

// Input: s = "tab a cat"

// Output: false
// Explanation: "tabacat" is not a palindrome.

// Constraints:

// 1 <= s.length <= 1000
// s is made up of only printable ASCII characters.

class Solution
{
public:
    bool isPalindrome(string s)
    {
        list<char> rev_s;
        list<char> org_s;
        for (char c : s)
        {
            if (isalnum(c))
            {
                rev_s.push_front(tolower(c));
                org_s.push_back(tolower(c));
            }
        }
        return rev_s == org_s;
    }
};
