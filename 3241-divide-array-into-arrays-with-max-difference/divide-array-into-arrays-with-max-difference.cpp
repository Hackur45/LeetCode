class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int i = 0;

        while (i <= (n - 3)) {
            if (nums[i + 2] - nums[i] <= k) {
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[i + 1]);
                temp.push_back(nums[i + 2]);
                ans.push_back(temp);
                i += 3;
            } else {
                return {};
            }
        }

        if (ans.size() * 3 != n) {
            return {};
        }

        return ans;
    }
};
