class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();

        for(int i=1;i<n;i++){
            int p1=nums[i-1]%2;
            int p2=nums[i]%2;
            if(p1 == p2) return false;
        }

        return true;
    }
};