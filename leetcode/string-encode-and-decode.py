from typing import List


def encode(self, strs: List[str]) -> str:
    return ''.join([str(len(s)) + '|' + s for s in strs])

def decode(self, s: str) -> List[str]:
    i = 0
    decoded_str = []
    while i < len(s):
        j = i
        while s[j] != '|':
            j += 1
        len_str = int(s[i:j]) # MODIFIED this was :j+1
        decoded_str.append(s[j+1:j+1+len_str])
        i = j + 1 + len_str
    return decoded_str