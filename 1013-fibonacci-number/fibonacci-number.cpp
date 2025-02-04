const int N = 1e5+10;
class Solution {
public:

//Dynamic Programming approach

    int dp[N];

    Solution() { 
        fill(dp, dp + N, -1); 
    }

    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(dp[n] != -1) return dp[n];

        return dp[n] = fib(n-1) + fib(n-2);
    }
};
