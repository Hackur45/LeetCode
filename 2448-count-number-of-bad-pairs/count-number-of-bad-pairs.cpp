#define ll long long
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        ll ans = 0;
        ll gp = 0;
        map<ll, int> mp;
        ll n = nums.size();

        for (ll i = 0; i < n; i++) {
            gp += mp[i - nums[i]];
            mp[i - nums[i]]++;
        }

        ll tp = n * (n - 1) / 2;

        return tp - gp;
    }
};