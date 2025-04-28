class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ans = 0, cs = 0;
        int i = 0;
        for (int j = 0; j < n; j++) {
            cs += nums[j];
            while (i <= j && cs * (j - i + 1) >= k) {
                cs -= nums[i];
                i++;
            }
            ans += (j - i + 1);
        }
        return ans;
    }
};
