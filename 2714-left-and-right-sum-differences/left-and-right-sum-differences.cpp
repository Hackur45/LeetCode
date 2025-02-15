class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        ___b();
        int n = nums.size();
        vector<int> pref(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1] + nums[i];
        }

        nums[0] = pref[n-1] - pref[0];

        for(int i=1;i<n;i++){
            nums[i] = abs(pref[i] - (pref[n-1] - pref[i-1])); 
        }

        return nums;
    }

private:
    void ___b(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
};