class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        set<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            if(i> 0 && nums[i] == nums[i-1]) continue;

            for(int j=i+1;j<n-2;j++){
                if(j > i +1 && nums[j] == nums[j-1]) continue;

                int l = j + 1;
                int r = n - 1;

                while(l < r){
                    long long sum = (long long)nums[l] + nums[r] + nums[i] + nums[j];

                    if(sum == target){
                        ans.insert({nums[i] , nums[j] , nums[l] , nums[r]});   
                        l++;
                        r--;
                   
                    }else if(sum < target){
                        l++;
                    }else{
                        r--;
                    }
                }
            }
        }

        vector<vector<int>> v;
        for(auto &a : ans){
            v.push_back(a);
        }
        return v;
    }
};