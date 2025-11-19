class Solution:
    def findFinalValue(self, l: List[int], original: int) -> int:
        a = list(set(l))
        while original in a:
            original *= 2
        
        return original