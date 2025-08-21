class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        priority_queue<int> pq;
        int n = nums.size();
        int m = nums[0].size();

        int ans = 0 ;

        for(auto &v : nums){
            sort(v.begin(),v.end());
        }
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                pq.push(nums[i][j]);
            }


            ans += pq.top();

            while(!pq.empty()) pq.pop();
        }

        return ans;
    }
};