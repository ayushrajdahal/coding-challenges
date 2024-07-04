# Is Anagram
# Solved 
# Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.

# An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

# Example 1:

# Input: s = "racecar", t = "carrace"

# Output: true
# Example 2:

# Input: s = "jar", t = "jam"

# Output: false
# Constraints:

def isAnagram(self, s: str, t: str) -> bool:
    if len(s) != len(t):
        return False
    s_counter = {}
    t_counter = {}
    
    for i in range(len(s)):
        s_counter[s[i]] = s_counter.get(s[i], 0) + 1
        t_counter[t[i]] = t_counter.get(t[i], 0) + 1

    return s_counter == t_counter