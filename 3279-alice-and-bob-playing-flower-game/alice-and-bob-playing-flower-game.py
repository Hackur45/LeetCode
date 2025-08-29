class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        e_n = sum(1 for i in range(1,n+1) if i%2 == 0)
        o_n = n - e_n
        e_m = sum(1 for i in range(1,m+1) if i%2 ==0)
        o_m = m - e_m

        ans = (e_n * o_m) + (o_n * e_m)
        return ans