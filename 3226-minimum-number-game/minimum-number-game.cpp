class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        ___b();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i=0; i<nums.size()-1; i+=2){
            int alice = nums[i];
            int bob = nums[i+1];
            ans.push_back(bob);
            ans.push_back(alice);
        }
        return ans;
    }

private:
    void ___b(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
};