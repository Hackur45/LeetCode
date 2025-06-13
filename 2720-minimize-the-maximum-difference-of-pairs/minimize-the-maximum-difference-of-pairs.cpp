class Solution {
public:
    bool canMakePairs(vector<int>& nums, int p, int maxDiff) {
        int count = 0;
        int i = 1;
        while (i < nums.size()) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                count++;
                i += 2; 
            } else {
                i++; 
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end()); 

        int l = 0;
        int n = nums.size();
        int r = nums[n-1] - nums[0];  

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (canMakePairs(nums, p, mid)) {
                r = mid; 
            } else {
                l = mid + 1;
            }
        }

        return l; 
    }
};
