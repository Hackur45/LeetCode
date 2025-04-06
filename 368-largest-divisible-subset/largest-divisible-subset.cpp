class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        sort(nums.begin(),nums.end());
        int n = nums.size();

        vector<int> dp(n,1);
        vector<int> prev(n,-1);

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j] == 0 && dp[j]+1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }

        int mi = 0;
        // for(int i=0;i<n;i++){
        //     mi = max(mi,prev[i]);
        // }
        int ma = 0;
        for(int i=0;i<n;i++){
            if(ma < dp[i]){
                mi = i;
                ma = dp[i];
            }
        }

        vector<int> ans;
        int bt = mi;
        while(bt != -1){
            ans.push_back(nums[bt]);
            bt = prev[bt];
        }
        
        return ans;
    }
};