class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + (nums[i - 1] % modulo == k ? 1 : 0);
        }

        unordered_map<int, long long> freq;
        freq[0] = 1;
        long long ans = 0;

        for (int i = 1; i <= n; i++) {
            int currMod = pre[i] % modulo;
            int targetMod = (currMod - k + modulo) % modulo;
            ans += freq[targetMod];
            freq[currMod]++;
        }

        return ans;
    }
};
