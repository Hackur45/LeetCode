class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        for i in range(1,n):
            a = n - i
            b = i
            m = list(str(a))
            l = list(str(b))
            if ('0' not in m) and ('0' not in l):
                return [a,b]

        return [] 