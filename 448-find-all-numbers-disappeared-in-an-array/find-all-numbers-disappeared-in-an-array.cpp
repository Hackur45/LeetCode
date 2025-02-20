class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        boostCode();
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;
            nums[index] = -abs(nums[index]);
        }

        vector<int> result;
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) result.push_back(i + 1);
        }

        return result;
    }

private:
    void boostCode(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
};
