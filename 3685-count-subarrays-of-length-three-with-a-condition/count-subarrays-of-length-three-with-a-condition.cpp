class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> subs;
        for(int i=0;i<=n-3;i++){
            vector<int> arr;
            for(int j=0;j<3;j++){
                arr.push_back(nums[i+j]);
            }
            subs.push_back(arr);
        }

        for(auto &a : subs){
            for(auto &k : a){
                cout<<k<<" ";
            }

            cout<<endl;
        }
        int ans = 0;
        for(auto &a : subs){
            int fts = a[0] + a[2];
            cout<<fts<<" "<<(a[1])<<endl;
            if(2*fts == a[1]) ans++;
        }

        return ans;
    }
};