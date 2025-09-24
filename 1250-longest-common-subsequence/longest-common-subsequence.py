class Solution:

    def lcs(self,memo,a,b,n,m) -> int:
        if n == 0 or m == 0:
            return 0

        if memo[n][m] != -1:
            return memo[n][m]
        
        if a[n-1] == b[m-1]:
            memo[n][m] = 1 + self.lcs(memo,a,b,n-1,m-1)
            return memo[n][m]
        else:
            memo[n][m] = max(self.lcs(memo,a,b,n,m-1),self.lcs(memo,a,b,n-1,m))
            return memo[n][m]

    def longestCommonSubsequence(self, a: str, b: str) -> int:
        memo = [[-1 for _ in range(len(b)+1)] for _ in range(len(a) + 1)]
        return self.lcs(memo,a,b,len(a),len(b))