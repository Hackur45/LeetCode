class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos =0 ;
        int neg=0;
        for(auto &a: nums){
            if(a != 0){
                if(a < 0) neg++;
                else pos++;
            }
        }
        return max(neg,pos);
    }
};