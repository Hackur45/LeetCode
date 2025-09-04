class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ps = 0;
        int ans = 0;
        unordered_map<int,int> pres;
        // pres[0] = 1;
        for(int i=0;i<n;i++){
            ps += nums[i];
            int complement = ps - k;

            if(ps == k) ans++;
            if(pres.find(complement) != pres.end()){
                ans += pres[complement];
            }

            pres[ps] += 1;
        }

        return ans;
    }
};