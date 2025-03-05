#define ll long long 
#define s 100007  
class Solution {
public:
    ll dp[s];
    ll helper(int n){
        if(n == 1){
            return 1;
        }

        if(dp[n] != 0){
            return dp[n];
        }

        return dp[n] = helper(n-1) +  (n-1) * 4;
    }
    long long coloredCells(int n) {
        ll ans = helper(n);
        for(int i=0;i<s;i++) dp[i] = 0;
        return ans;
    }
};