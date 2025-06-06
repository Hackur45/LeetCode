#include <vector>
using namespace std;

class Solution {
public:
    bool canZeroOut(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        vector<int> temp_nums = nums; 
        
      
        for (int i = 0; i < k; ++i) {
            int l = queries[i][0], r = queries[i][1], val = queries[i][2];
            diff[l] -= val;
            if (r + 1 < n) diff[r + 1] += val;
        }
        
        int curr_decrement = 0;
        for (int i = 0; i < n; ++i) {
            curr_decrement += diff[i]; 
            if (temp_nums[i] + curr_decrement > 0) return false; 
        }
        
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 0, right = queries.size(), answer = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canZeroOut(nums, queries, mid)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1; 
            }
        }
        
        return answer;
    }
};
