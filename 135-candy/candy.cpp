class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> allocs(n,1);
        int ans = 0;
        for(int i=1;i<n;i++){
            if(ratings[i] > ratings[i-1]) allocs[i] = allocs[i-1] + 1;
        }

        for(int i=n-1;i>0;i--){
            if(ratings[i-1] > ratings[i]){
                allocs[i-1] = max(allocs[i] + 1 , allocs[i-1]);          
            }
            ans += allocs[i-1];
        }

        return ans + allocs[n-1];
    }
};