class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        set<int> st(nums.begin(), nums.end());
        int k = st.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            set<int> sub;
            for (int j = i; j < n; ++j) {
                sub.insert(nums[j]);
                if (sub.size() == k) {
                    ans++;
                }
            }
        }

        return ans;
    }
};