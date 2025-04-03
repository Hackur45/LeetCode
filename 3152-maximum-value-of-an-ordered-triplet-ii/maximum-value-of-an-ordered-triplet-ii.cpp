class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        long long res = 0;
        int a = nums[0];
        vector<int> b(n, 0);

        b[n-1] = nums[n-1];
        for (int i = n - 2; i >= 0; i--) {
            b[i] = max(b[i+1], nums[i]);
        }

        for (int j = 1; j < n - 1; j++) {
            res = max(res, (long long)(a - nums[j]) * b[j+1]);
            a = max(a, nums[j]);
        }

        return res;
    }
};
