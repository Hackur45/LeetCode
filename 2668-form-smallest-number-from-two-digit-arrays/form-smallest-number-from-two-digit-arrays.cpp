class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(auto &a:nums1) mp[a]++;
        for(auto &a:nums2) mp[a]++;

        vector<int> ans;
        for(auto &[key,val]:mp){
            if(val >= 2){
                ans.push_back(key);
            }
        }

        int ma = *min_element(nums1.begin(),nums1.end());
        int mb = *min_element(nums2.begin(),nums2.end());
        
        ans.push_back(ma * 10 + mb);
        ans.push_back(mb * 10 + ma);

        int fs = *min_element(ans.begin(),ans.end());
        return fs;
    }

};