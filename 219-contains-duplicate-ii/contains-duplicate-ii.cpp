class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        int i=0;
        for(int &a : nums){
            if(st.find(a) != st.end()) return true;

            st.insert(a);
            if(st.size() > k) st.erase(nums[i-k]);
            i++;
        }   
        return false;
    }
};