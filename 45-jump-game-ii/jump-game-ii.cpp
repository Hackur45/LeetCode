class Solution {
public:
    int solve(vector<int> &nums){
        int jumps = 0, l = 0, r=0;
        int n = nums.size();
        while(r < n-1){
            int far = 0;
            for(int index = l; index <= r ;index++){
                far = max(far,index+nums[index]);
            }
            l = r + 1;
            r = far;
            jumps++;
        }

        return jumps;
    }
    int jump(vector<int>& nums) {
        int ans = solve(nums);
        return ans;
    }
};