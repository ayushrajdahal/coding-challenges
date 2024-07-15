// Validate Parentheses
// You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.

// The input string s is valid if and only if:

// Every open bracket is closed by the same type of close bracket.
// Open brackets are closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
// Return true if s is a valid string, and false otherwise.

// Example 1:

// Input: s = "[]"

// Output: true
// Example 2:

// Input: s = "([{}])"

// Output: true
// Example 3:

// Input: s = "[(])"

// Output: false
// Explanation: The brackets are not closed in the correct order.

// Constraints:

// 1 <= s.length <= 1000

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> group;
        unordered_map<char, char> rev = {
            {'}', '{'},
            {']', '['},
            {')', '('}};

        for (int i = 0; i < s.length(); i++)
        {
            char curr_char = s[i];
            if (rev.find(curr_char) == rev.end())
            {
                group.push(curr_char);
            }
            else
            {
                if (group.empty() || rev[curr_char] != group.top())
                {
                    return false;
                }
                group.pop();
            }
        }
        return group.empty();
    }
};
