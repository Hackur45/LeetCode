#define ll long long int 
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll n = nums.size();
        ll l = 0, r = 0;
        ll count = 0;
        ll me = *max_element(nums.begin(),nums.end());
        for(auto &a : nums){
            if(a == me) count++;
        }

        if(count < k){
            return 0;
        }

        ll ans = 0;
        count = 0;
        while(r < n){
            if(nums[r] == me){
                count++;
            }
            // cout<<count<<" "<<k<<endl;
            while(count >= k){
                ans += (n-r);
                if(nums[l] == me){
                    count--;
                }
                l++;
            }

            r++;
        }

        return ans;
    }
};