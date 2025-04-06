class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJ = 0;

        int n = nums.size();

        if(n == 1){
            return true;
        }
        for(int i=0;i<n;i++){
            // int jump = nums[i] + i;
            // if(jump > maxJ){
            //     maxJ += jump;
            // }
            if(i > maxJ) return false;
            maxJ = max(maxJ,i+nums[i]);
        }

        if(maxJ >= nums.size()-1){
            return true;
        }

        return false;
    }
};