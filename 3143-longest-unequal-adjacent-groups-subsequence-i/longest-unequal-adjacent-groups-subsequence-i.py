from typing import List

class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        l = [words[i] for i in range(1,len(words)) if groups[i-1] != groups[i]]
        l.insert(0, words[0])  
        return l
