// String Encode and Decode
// Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.

// Please implement encode and decode

// Example 1:

// Input: ["neet","code","love","you"]

// Output:["neet","code","love","you"]
// Example 2:

// Input: ["we","say",":","yes"]

// Output: ["we","say",":","yes"]
// Constraints:

// 0 <= strs.length < 100
// 0 <= strs[i].length < 200
// strs[i] contains only UTF-8 characters.

class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string merged_s = "";
        for (string s : strs)
        {
            merged_s = merged_s + to_string(s.length()) + "#" + s; // MODIFIED: string() changed into to_string()
        }
        return merged_s;
    }

    vector<string> decode(string s)
    {
        vector<string> decoded_str;
        int curr_idx = 0;
        int str_len = s.length();
        int len_to_fetch;
        while (curr_idx < str_len)
        {
            // initial_idx is the position where the len_to_fetch value starts. curr_idx gets incremented till it reaches '#'
            // initialized here instead of inside else block that contained codeblock for non-hashtag case
            int initial_idx = curr_idx;
            while (s[curr_idx] != '#')
            {
                curr_idx++;
            }

            // MODIFIED: int() changed into stoi()
            len_to_fetch = stoi(s.substr(initial_idx, curr_idx - initial_idx));

            // decodes one whole string in one go, updates the index to the next charcount-containing index
            decoded_str.push_back(s.substr(curr_idx + 1, len_to_fetch));
            curr_idx = curr_idx + len_to_fetch + 1;
        }
        return decoded_str;
    }
};
