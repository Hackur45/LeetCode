class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        ___b();
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> arr;
        int i=0;
        while(i < n){
            int alice = nums[i];
            i++;
            if(i >= n) break;
            int bob = nums[i];
            i++;
            arr.push_back(bob);
            arr.push_back(alice);
        }

        return arr;
    }

private:
    void ___b(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
};